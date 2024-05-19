/*
c++沉思录里77页 实验基于继承的 语法树打印
*/

#include<iostream>
#include<string>

class Expr;

class Node
{
    friend class Expr;
    friend std::ostream& operator<<(std::ostream&, const Node&);
    int use;
public:
    Node():use(1){}
    virtual void print(std::ostream&) const = 0;
    virtual ~Node(){}
};

std::ostream& operator<<(std::ostream& o, const Node& n)
{
    n.print(o);
    return o;
}

//int 数据节点
class Int_node : public Node
{
    friend class Expr;
    int n;
    Int_node(int i):n(i){}
    void print(std::ostream& o) const{o << n;}
};

//一元运算符
class Unary_node : public Node
{
    friend class Expr;
    std::string op;
    Expr right;
    
    Unary_node(const std::string& a, Expr n):op(a),right(n){}

    void print(std::ostream& o) const 
    {
        o << "(" << op << right << ")";
    }
};

//二元运算符
class Binary_node : public Node
{
    friend class Expr;

    std::string op;
    Expr left;
    Expr right;

    Binary_node(const std::string& a,  Expr l, Expr r): op(a), left(l), right(r){}
public:
    void print(std::ostream& o) const
    {
        o << "(" << left << op << right << ")";
    }
};

//用以创建节点
class Expr
{
    friend std::ostream& operator <<(std::ostream&, const Expr&);
    Node* n;
public:
    
    Expr(int i) //创建整型节点 
    {
        n = new Int_node(i);
    }

    Expr(const std::string& op, Expr t)//创建一元节点
    {
        n = new Unary_node(op, t);
    }

    Expr(const std::string& op, Expr l, Expr r)//创建二元节点
    {
        n = new Binary_node(op, l, r);
    }

    Expr(const Expr& t)//复制构造
    {
        n = t.n; 
        ++ n->use;
    } 

    Expr& operator=(const Expr& ex)
    {
        ex.n -> use++;
        if(-- n->use == 0)
            delete n;
        n = ex.n;
        return *this;
    }
    
    ~Expr()
    {
        if(-- n->use == 0 )
            delete n;
    }

};

std::ostream& operator <<(std::ostream& o, const Expr& e)
{
    e.n->print(o);
    return o;
}


int main()
{
    std::cout<<"hi"<<std::endl;

    Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
}