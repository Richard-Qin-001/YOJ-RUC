#include <iostream>
#include <stdio.h>
using namespace std;

class RGraph
{
public:
    RGraph(int n = 1, int m = 2, char ch = '*');
    ~RGraph();

    void readRule(); // 读入规则方阵
    void draw();     // 画出图形矩阵

private:
    int mPow(int x);   // 计算图形(子)矩阵的大小
    void initiGraph(); // 初始化图形矩阵:所有元素置为空格
    /*
     * 功能: 递归打印图形矩阵中的字符点dot
     * n: 图形的层级
     * row: 图形矩阵中的行号, 0开始;
     * col: 图形矩阵中的列号, 0开始;
     * */
    void drawDot(int n, int row, int col);

private:
    int n;          // 递归图形的层级
    int m;          // 规则方阵大小
    char dot;       // 图形中的字符点
    int size;       // 图形矩阵的大小
    int rule[3][3]; // 规则矩阵
    char **matrix;  // 图形矩阵地址, matrix相当于数组名
};

// 构造函数(默认)
RGraph::RGraph(int n, int m, char ch) : n(n), m(m), dot(ch), matrix(NULL)
{
    if (n < 1 || n > 10)
        return;
    if (!(m == 2 || m == 3))
        return;

    size = mPow(n - 1); // 图形矩阵大小

    matrix = new char *[size];
    for (int i = 0; i < size; i++)
    {
        // 矩阵每行额外1个结束标记
        matrix[i] = new char[size + 1];
    }
    initiGraph();
}

// 析构函数(释放字符图形矩阵)
RGraph::~RGraph()
{
    if (matrix == NULL)
        return;

    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

// 读入规则方阵
void RGraph::readRule()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> rule[i][j];
        }
    }
}

void RGraph::draw()
{
    drawDot(n, 0, 0);
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", matrix[i]);
    }
}

int RGraph::mPow(int x)
{
    int mp = 1;

    for (int i = 0; i < x; i++)
    {
        mp *= m;
    }

    return mp;
}

// 此处完成成员函数initiGraph和drawDot
void RGraph::initiGraph()
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            matrix[i][j] = ' ';
        }
        matrix[i][size] = '\0';
    }
}

void RGraph::drawDot(int n, int row, int col)
{
    if (n == 1)
    {
        matrix[row][col] = dot;
        return;
    }

    int cs = 1;
    for (int i = 0; i < n - 2; ++i)
        cs *= m;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (rule[i][j] == 1)
            {
                RGraph::drawDot(n - 1, row + i * cs, col + j * cs);
            }
        }
    }
}

int main()
{
    char dot;
    int n, m;

    cin >> dot >> n;
    cin >> m;

    RGraph graph(n, m, dot);
    graph.readRule();

    graph.draw();

    return 0;
}
