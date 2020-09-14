//===-----------------------------------------
//     Union Find
//     并查集 v 1.0
//
//===-----------------------------------------
// union (p, q);          求元素P和q的并集
// find  (p);             查找元素p所在的集合
// is_connected(p, q);    p和q是否相连


#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <cassert>



/**
 * 一个最简单的并查集实现, 采用集合id数组, 不过并操作的效率不高.
 */
class UnionFind{

private:
    int * id;       // id数组, 指出顶点所在的集合
    int count;       // 并查集中元素的数量

public:
    explicit UnionFind(int size): count(size){
        id = new int[size];

        // 初始状态下, 每个元素都在不同的集合中
        for (int i = 0; i < size; i++){
            id[i] = i;
        }
    }

    ~UnionFind(){
        delete[] this->id;
    }

public:
    /**
     * 取得 元素p 所在的集合
     * @param p
     * @return
     */
    int find(int p){
        assert( p >= 0 && p < count);

        // 返回 元素p所在的集合id号
        return id[p];
    }

    /**
     * 判断 元素P 和 元素q 在不在一个集合内
     * @param p
     * @param q
     * @return
     */
    bool is_connected( int p, int q){
        // p 和 q 相连接的前提是, 处在同一集合中, 即他们所在的
        // 集合id是相同的.
        return ( find(p) == find(q) );
    }

    /**
     * 求两个元素的并集.
     * O(n)
     * @param p
     * @param q
     */
    void union_elems( int p, int q ){
        int p_id = this->find(p);   // 取得 p 所在的集合
        int q_id = this->find(q);   // 取得 q 所在的集合

        // 如果 p 和 q 已经在一个集合里, 无需做并操作
        if ( p_id == q_id ) {
            return;
        }

        // 如果 p 和 q 还不在一个集合里, 需要做并操作
        for ( int i = 0; i < count; i++) {
            if (id[i] == p_id) id[i] = q_id;
        }
    }

};

/**
 * 采用逆二叉树
 */
class QuickUnion{

private:
    int * parent;
    int   count;

    // Ctor & dtor
public:
    explicit QuickUnion(int count) {
        this->parent = new int[count];
        for(int i = 0; i < count; i++){
            parent[i] = i;
        }

        this->count = count;
    }

    ~QuickUnion(){
        delete[] this->parent;
    }

public:

    int find(int p){
        assert(p >= 0 && p < count);

        while (p != parent[p]){
            p = parent[p];
        }

        return p;
    }

    bool is_connected(int p, int q){
        return find(p)==find(q);
    }

    void union_elems(int p, int q){
        int p_root = find(p);
        int q_root = find(q);

        if (p_root == q_root) return;

        parent[p_root] = q_root;
    }
};

#endif //UNION_FIND_H
