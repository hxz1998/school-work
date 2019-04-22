//
// Created by Monkey on 2019/1/4.
//

#define DataType int
#define MAXVALUE 1000
#define MAXBIT 20

#include <stdio.h>
#include <cstdlib>

/**
 * 哈夫曼书的节点
 */
typedef struct node {
    DataType data;      //数据域
    int weight;         //权值域
    int parent;         //双亲域
    int left;           //左孩子域
    int right;          //右孩子域
} HuffmanNode;

/**
 * 哈夫曼编码
 */
typedef struct {
    char code[MAXBIT];  //哈夫曼编码值
    int start;          //编码起始位置
} Code;

/**
 * 创建哈夫曼树
 *
 * @param weight 节点权重
 * @param ch
 * @param n
 * @param hf
 */
void HuffmanTree(int weight[], char ch[], int n, HuffmanNode hf[]) {
    int i, j, mw1, mw2, node1, node2;
    //对哈夫曼树进行初始化
    for (i = 0; i < 2 * n - 1; i++) {
        if (i < n) {
            hf[i].weight = weight[i];
            hf[i].data = ch[i];
        } else
            hf[i].weight = 0;
        hf[i].parent = -1;
        hf[i].left = -1;
        hf[i].right = -1;
    }
    for (i = n; i < 2 * n - 1; i++) {
        mw1 = mw2 = MAXVALUE;
        node1 = node2 = -1;
        for (j = 0; j <= i - 1; j++) {//在双亲域为-1的结点中寻找两个权值最小的结点
            if (hf[j].parent == -1) {
                if (hf[j].weight < mw1) {
                    mw2 = mw1;
                    node2 = node1;
                    mw1 = hf[j].weight;
                    node1 = j;
                } else if (hf[j].weight < mw2) {
                    mw2 = hf[j].weight;
                    node2 = j;
                }
            }
        }
        //开始构造新的二叉树
        hf[i].weight = hf[node1].weight + hf[node2].weight;
        hf[node1].parent = i;
        hf[node2].parent = i;
        hf[i].left = node1;
        hf[i].right = node2;
    }
}


/**
 * 哈夫曼编码
 * @param huffman
 * @param huffmanCode
 * @param n
 */
void HuffmanCode(HuffmanNode huffman[], Code huffmanCode[], int n) {
    int i, parent, left;
    Code hc;
    for (i = 0; i < n; i++) {
        hc.start = n;
        left = i;
        parent = huffman[i].parent;
        while (parent != -1) {//有双亲结点，说明没有到达根结点
            if (huffman[parent].left == left)
                hc.code[hc.start--] = '0';//是左孩子
            else
                hc.code[hc.start--] = '1';//是右孩子
            left = parent;
            parent = huffman[parent].parent;   //向根进发
        }
        hc.start++;
        huffmanCode[i] = hc;  // 获取一个编码
    }
}

int main() {
    int i, j, n = 5;
    char ch[] = "ABCDE";
    int weight[] = {3, 8, 6, 1, 5};
    //为哈夫曼树开辟内存空间
    HuffmanNode *HufTree = (HuffmanNode *) malloc(sizeof(Code) * (2 * n + 1));
    //为哈夫曼编码开辟内存空间
    Code *HufCodes = (Code *) malloc(sizeof(Code) * n);
    HuffmanTree(weight, ch, n, HufTree);//创建
    printf("\n对哈夫曼进行初始化存储\n");
    printf("数据： 序号    权值    双亲   左孩子   右孩子\n");
    for (i = 0; i <= n - 1; i++) {//前n个结点
        printf("%c\t%d\t%d\t%d\t%d\t%d\n", HufTree[i].data, i, HufTree[i].weight, HufTree[i].parent, HufTree[i].left,
               HufTree[i].right);
    }
    for (i = n; i < 2 * n - 1; i++) {//后n-1个结点
        printf("\t%d\t%d\t%d\t%d\t%d\n", i, HufTree[i].weight, HufTree[i].parent, HufTree[i].left, HufTree[i].right);
    }
    HuffmanCode(HufTree, HufCodes, n);    //编码
    printf("\n哈夫曼编码\n");
    for (i = 0; i < n; i++) {
        printf("%c(%d):\t", ch[i], HufTree[i].weight);
        for (j = HufCodes[i].start; j <= n; j++)
            printf("%c", HufCodes[i].code[j]);
        printf("\n");
    }
    return 0;
}


