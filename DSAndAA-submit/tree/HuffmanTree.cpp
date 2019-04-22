//
// Created by Monkey on 2019/1/4.
//

#define DataType int
#define MAXVALUE 1000
#define MAXBIT 20

#include <stdio.h>
#include <cstdlib>

/**
 * ��������Ľڵ�
 */
typedef struct node {
    DataType data;      //������
    int weight;         //Ȩֵ��
    int parent;         //˫����
    int left;           //������
    int right;          //�Һ�����
} HuffmanNode;

/**
 * ����������
 */
typedef struct {
    char code[MAXBIT];  //����������ֵ
    int start;          //������ʼλ��
} Code;

/**
 * ������������
 *
 * @param weight �ڵ�Ȩ��
 * @param ch
 * @param n
 * @param hf
 */
void HuffmanTree(int weight[], char ch[], int n, HuffmanNode hf[]) {
    int i, j, mw1, mw2, node1, node2;
    //�Թ����������г�ʼ��
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
        for (j = 0; j <= i - 1; j++) {//��˫����Ϊ-1�Ľ����Ѱ������Ȩֵ��С�Ľ��
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
        //��ʼ�����µĶ�����
        hf[i].weight = hf[node1].weight + hf[node2].weight;
        hf[node1].parent = i;
        hf[node2].parent = i;
        hf[i].left = node1;
        hf[i].right = node2;
    }
}


/**
 * ����������
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
        while (parent != -1) {//��˫�׽�㣬˵��û�е�������
            if (huffman[parent].left == left)
                hc.code[hc.start--] = '0';//������
            else
                hc.code[hc.start--] = '1';//���Һ���
            left = parent;
            parent = huffman[parent].parent;   //�������
        }
        hc.start++;
        huffmanCode[i] = hc;  // ��ȡһ������
    }
}

int main() {
    int i, j, n = 5;
    char ch[] = "ABCDE";
    int weight[] = {3, 8, 6, 1, 5};
    //Ϊ�������������ڴ�ռ�
    HuffmanNode *HufTree = (HuffmanNode *) malloc(sizeof(Code) * (2 * n + 1));
    //Ϊ���������뿪���ڴ�ռ�
    Code *HufCodes = (Code *) malloc(sizeof(Code) * n);
    HuffmanTree(weight, ch, n, HufTree);//����
    printf("\n�Թ��������г�ʼ���洢\n");
    printf("���ݣ� ���    Ȩֵ    ˫��   ����   �Һ���\n");
    for (i = 0; i <= n - 1; i++) {//ǰn�����
        printf("%c\t%d\t%d\t%d\t%d\t%d\n", HufTree[i].data, i, HufTree[i].weight, HufTree[i].parent, HufTree[i].left,
               HufTree[i].right);
    }
    for (i = n; i < 2 * n - 1; i++) {//��n-1�����
        printf("\t%d\t%d\t%d\t%d\t%d\n", i, HufTree[i].weight, HufTree[i].parent, HufTree[i].left, HufTree[i].right);
    }
    HuffmanCode(HufTree, HufCodes, n);    //����
    printf("\n����������\n");
    for (i = 0; i < n; i++) {
        printf("%c(%d):\t", ch[i], HufTree[i].weight);
        for (j = HufCodes[i].start; j <= n; j++)
            printf("%c", HufCodes[i].code[j]);
        printf("\n");
    }
    return 0;
}


