public class BiNode {
    private int data;
    private BiNode leftChild;
    private BiNode rightChild;

    public int getData(){
        return this.data;
    }

    public BiNode(int data, BiNode leftChild, BiNode rightChild) {
        this.data = data;
        this.leftChild = leftChild;
        this.rightChild = rightChild;
    }

    public void setData(int data){
        this.data = data;
    }

    public BiNode getLeftChild() {
        return leftChild;
    }

    public void setLeftChild(BiNode leftChild) {
        this.leftChild = leftChild;
    }

    public BiNode getRightChild() {
        return rightChild;
    }

    public void setRightChild(BiNode rightChild) {
        this.rightChild = rightChild;
    }

}
