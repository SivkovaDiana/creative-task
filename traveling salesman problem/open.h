#pragma once
#include <glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <cmath>
using namespace std;

const int maxSize = 15;                      //максимальное число вершин
extern int WinW;
extern int WinH;
struct vertCoord
{
	int x, y;
};

class Graph
{
private:
	vector<int> vertList;
	int adjMatrix[maxSize][maxSize];
public:
	Graph();
	~Graph();
	bool IsEmpty();                                                              //определяет пустой граф или полный
	bool IsFull();

	int getVertText(int i) { return vertList[i]; }                               //позволяет получить новые значения вершины
	vector<int> getVertList() { return  vertList; }                              //позволет получить вектор вершин
	int getAdjMatrixElem(int i, int j) { return adjMatrix[i][j]; }               //позволет получить элемент матрицы смежности
	void setEdgeZero(int i, int j) { adjMatrix[i][j] = 0; adjMatrix[j][i] = 0; } //позволет занулить элемент матрицы
	int GetAmountVerts() { return vertList.size(); }                             //позволет получить количество вершни графа
	int GetVertPos(const int& vertex);		                                     //позволет получить позицию вершины в векторе вершин
	int GetAmountEdges();                                                        //позволет получить количество ребер графа
	void InsertVertex(const int& vertex);					                     //позволет добавить вершину
	void InsertEdge(const int& vertex1, const int& vertex2, int weigth);	     //позволет добавить ребро
	void Print();		                                                         //вывод матрицы смежности в консоль
	void eraseLastVert();                                                        //позволет удалить последнюю вершину в векторе вершин
	void eraseEdge(const int& vertex1, const int& vertex2);                      //позволет удалить ребро
	void drawGraph();                                                            //отрисовка графа
};
extern Graph graph;		                                                         //создается объект графа

int** Make_TSPMatrix();	                                                         //создается матрица, заменяя 0 на -1
int* Find_Min(int* line, int n);	                                             //поиск минимального объекта в строке матрицы
void Print_Matrix(int** matrix);		                                         //вывод текущей матрицы
int** Reduct_Matrix(int** oldmatrix);		                                     //редукция матрицы
int** Rebuild_Matrix(int** oldmatrix);
void Print_Result();                                                             //вывод результата решения

void drawButton1();
void drawButton2();
void drawButton3();
void drawButton4();
void drawButton5();

void drawCircle(int x, int y, int R);
void drawBorderedCircle(int x, int y, int R);
void drawText(int nom, int x1, int y1);
void drawLine(int text, int x0, int y0, int x1, int y1);
void drawVertex(int n);

void makeGraph();
void setCoords(int i, int n);

bool Salesman_Check(int** matrix);
int Circle_Check(int x, int y);
void Button_Check(int x, int y);

void mouseMove(int x, int y);
void mouseClick(int button, int state, int x, int y);
void reshape(int w, int h);
void display();