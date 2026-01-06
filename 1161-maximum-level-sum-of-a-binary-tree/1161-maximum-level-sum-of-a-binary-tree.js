/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxLevelSum = function(root) {
    
    if (root === null) {
      return -1;
    }

    let maxLevel = 1;
    let maxSum = root.val; 
    let level = 1;

    const queue = [];
    queue.push(root);

    while (queue.length > 0) {
      const levelSize = queue.length;
      let levelSum = 0;

      for (let i = 0; i < levelSize; i++) {
        const curr = queue.shift();

        levelSum += curr.val;

        if (curr.left !== null) {
          queue.push(curr.left);
        }

        if (curr.right !== null) {
          queue.push(curr.right);
        }
      }

      if (levelSum > maxSum) {
        maxSum = levelSum;
        maxLevel = level;
      }

      level++;
    }

    return maxLevel;
  
};