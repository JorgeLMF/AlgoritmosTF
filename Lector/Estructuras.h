#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
struct TreeNode {
    T data;
    vector<TreeNode<T>*> child;
    TreeNode(T data) :data(data) {}
};

template <typename T>
class GenericTree {
public:
    TreeNode<T>* root;
    GenericTree(TreeNode<T>* root = nullptr) :root(root) {}

    void AddChildToRoot(T data) {
        AddChildToNode(this->root, data);
    }

    void AddChildToRoot(TreeNode<T>* node) {
        this->root->child.push_back(node);
    }

    void AddChildToNode(TreeNode<T>* treenode, T data) {
        treenode->child.push_back(new TreeNode(data));
    }

    void OrderTraversal() { OrderTraversal(this->root); }
    void OrderTraversal(TreeNode<T>* root) {
        if (root == nullptr)
            return;

        queue<TreeNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            while (n > 0) {
                TreeNode<T>* p = q.front();
                q.pop();
                cout << p->data << " ";

                for (int i = 0; i < p->child.size(); i++) {
                    q.push(p->child[i]);
                }
                n--;
            }
            cout << endl;
        }
    }

};

template <typename T>
struct Nodo {
    T valor;
    Nodo* siguiente;
    Nodo* anterior;
    Nodo(T v, Nodo* s = nullptr, Nodo* a = nullptr) : valor(v), siguiente(s), anterior(a) {}
};

template <class T>
class ListaDoble {
private:
    Nodo<T>* inicio;
    Nodo<T>* fin;
    unsigned long cantidad;
public:
    ListaDoble() {
        inicio = fin = nullptr;//lista vacia
        cantidad = 0;
    }

    void anteponer(T v) {
        Nodo<T>* nuevo = new Nodo<T>(v);
        if (cantidad == 0)
            fin = nuevo;
        else
        {
            nuevo->siguiente = inicio;
            inicio->anterior = nuevo;
        }

        inicio = nuevo;
        ++cantidad;
    }
    void imprimir() {
        Nodo<T>* aux = inicio;
        while (aux != nullptr) {
            cout << aux->valor << "-->";
            aux = aux->siguiente;
        }
        cout << "nullptr" << endl;
    }

    T recuperar(unsigned long pos) {

        Nodo<T>* aux = inicio;
        if (pos <= cantidad) {
            for (int i = 0; i < pos; ++i)
                aux = aux->siguiente;
        }
        else exit(-1);
        return aux->valor;
    }
    Nodo<G>* get(unsigned long pos) {
        Nodo<T>* aux = inicio;
        if (pos <= cantidad) {
            for (int i = 0; i < pos; ++i)
                aux = aux->siguiente;
        }
        else nullptr;
        return aux;
    }


    /*void insertar_fin_f1(T v){//en tiempo N
        Nodo<T>* nuevo=new Nodo<T>(v);
        Nodo<T>* aux=inicio;
        if(cantidad==0)
          inicio=nuevo;
        else{
            while(aux!=nullptr){
              aux=aux->siguiente;
            }
        aux->siguiente=nuevo;
        }
        ++cantidad;
    }*/
    void insertar(T v) {//en O(1)
        Nodo<T>* nuevo = new Nodo<T>(v);
        if (cantidad == 0)
            inicio = fin = nuevo;
        else {
            fin->siguiente = nuevo;
            nuevo->anterior = fin;
            fin = nuevo;
        }
        ++cantidad;
    }
    //insertar valor por posicion
    void insertarPorPos(T v, long pos) {
        //if(pos<0||pos>cantidad)return;
        if (pos <= 0)
            anteponer(v);
        else if (pos >= cantidad)
            insertar(v);
        else {
            Nodo<T>* aux = inicio;
            if (pos <= cantidad) {
                for (int i = 0; i < pos - 1; ++i)
                    aux = aux->siguiente;
            }
            Nodo<T>* nuevo = new Nodo<T>(v);
            nuevo->siguiente = aux->siguiente;
            nuevo->anterior = aux;
            aux->siguiente = nuevo;
            nuevo->siguiente->anterior = nuevo;
            ++cantidad;
        }
    }
    void insertarPorPosv2(T v, long pos) {
        Nodo<T>* aux;
        if (pos <= 0)
            anteponer(v);
        else if (pos >= cantidad)
            insertar(v);
        else {
            aux = fin;
            for (int i = 0; i < cantidad - pos; ++i)
                aux = aux->anterior;
        }
        Nodo<T>* nuevo = new Nodo<T>(v);

        nuevo->siguiente = aux;
        nuevo->anterior = aux->anterior;
        aux->anterior = nuevo;
        nuevo->anterior->siguiente = nuevo;
        ++cantidad;

    }
    void eliminarInicio() {
        if (cantidad == 0)return;
        else if (cantidad == 1)
            fin = nullptr;
        Nodo<T>* aux = inicio;
        inicio = inicio->siguiente;
        inicio->anterior = nullptr;
        delete aux;
        --cantidad;
    }
    //eliminar en posicion
    //unir dos listas simples
    void merge(ListaDoble<T>& lista2) {
        if (cantidad == 0)
            inicio = fin = lista2->get(0);//inicio=fin->lista2->inicio;
        else
            fin->siguiente = lista2->get(0);

    }
    //ordenar asc
    //invertir lista
    //buscar en posicion
};