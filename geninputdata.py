#!/usr/bin/python
#-*- coding: UTF-8 -*-

import io
import sys
from collections import deque

class Count :
    def __init__(self, count = 0):
        self.count = count 
        
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def generateTreeFromArray(nodes):
    root_val = int(nodes[0]) if nodes[0] != 'null' else None
    if root_val is None:
        return None
    
    root = TreeNode(root_val)    
    queue = deque([root])
    index = 1
    
    while queue and index < len(nodes):
        current = queue.popleft()
        
        # 处理左子节点
        if index < len(nodes) and nodes[index] != 'null':
            left_val = int(nodes[index])
            current.left = TreeNode(left_val)
            queue.append(current.left)
        index += 1
        
        # 处理右子节点
        if index < len(nodes) and nodes[index] != 'null':
            right_val = int(nodes[index])
            current.right = TreeNode(right_val)
            queue.append(current.right)
        index += 1
    
    return root
   
def writeTreeNodeAsCode(node, nodeIndexMap, buffer, count):
    if node != None:
        writeTreeNodeAsCode(node.left, nodeIndexMap, buffer, count)
        writeTreeNodeAsCode(node.right, nodeIndexMap, buffer, count)
        nodeCount = count.count 
        
        if node.left != None and node.right != None:
            buffer.write('TreeNode node{}({}, &node{}, &node{});\n'.format(nodeCount, node.val, nodeIndexMap[node.left], nodeIndexMap[node.right]))
        elif node.left != None and node.right == None:
            buffer.write('TreeNode node{}({}, &node{}, nullptr);\n'.format(nodeCount, node.val, nodeIndexMap[node.left]))
        elif node.left == None and node.right != None:
            buffer.write('TreeNode node{}({}, nullptr, &node{});\n'.format(nodeCount, node.val, nodeIndexMap[node.right]))
        else:
            buffer.write('TreeNode node{}({}, nullptr, nullptr);\n'.format(nodeCount, node.val))
        
        nodeIndexMap[node] = nodeCount;
        count.count = nodeCount + 1
    
args = sys.argv
argc = len(args)

if argc < 3:
    sys.exit()
    
inputData = args[1]
dataType = args[2]

optimizedInputData = inputData.removeprefix('[').removesuffix(']')
nodes = optimizedInputData.split(',')

nodeCount = len(nodes)
print(nodeCount)

if nodeCount == 0:
    sys.exit()
    
nodeIndex = 0
buffer = io.StringIO()
if dataType == 'link':
    buffer.write('ListNode node{}({}, nullptr);\n'.format(nodeIndex, nodes[nodeCount - 1]))
    nodeIndex += 1
    for i in range(nodeCount - 2, -1, -1):
       buffer.write('ListNode node{}({}, &node{});\n'.format(nodeIndex, nodes[i], nodeIndex - 1));
       nodeIndex += 1
elif dataType == 'tree':
    count = Count(0)
    nodeIndexMap = dict()
    
    root = generateTreeFromArray(nodes)
    writeTreeNodeAsCode(root, nodeIndexMap, buffer, count)
    
print(buffer.getvalue())   
            
    
                
            
            
        
            
            
        
        
    