import java.util.LinkedList;
import java.util.Queue;
/*
用层次分析法来遍历二叉树
（当队列中取出一个节点，同时将其的左右节点放入队列中）
 */
public class CengXuBianLi {
    public static void main(String[] args) {
        BiNode node1,node2,node3,node4 = null;
        node4 = new BiNode(4,null,null);
        node3 = new BiNode(3,null,null);
        node2 = new BiNode(2,node4,null);
        node1 = new BiNode(1,node2,node3);
        BiTree tree = new BiTree(node1);
        Queue queue = new LinkedList<BiNode>();
        queue.add(tree.getRoot());
        while (!queue.isEmpty()){
            BiNode delNode = (BiNode) queue.poll();
            System.out.println(delNode.getData()+"\t");
            if (delNode.getLeftChild() != null) {
                queue.add(delNode.getLeftChild());
            }
            if (delNode.getRightChild() != null) {
                queue.add(delNode.getRightChild());
            }
        }
    }
}
