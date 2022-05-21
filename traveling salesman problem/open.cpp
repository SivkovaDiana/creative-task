#include "open.h"
using namespace std;
int WinW = 1000;
int WinH = 600;

bool* Mouse_Vert = new bool[maxSize];
bool standView = false;
bool Vert_Move = false;

vector<pair<int, int>> Path;
vector<int> NewPath;
int R;

int Moving_Vertex;
int CursorX;
int CursorY;

vertCoord vertC[maxSize + 1];
Graph graph;
int Button_Flag;

Graph::Graph()
{
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			adjMatrix[i][j] = 0;
		}
		Mouse_Vert[i] = false;
	}
}

Graph::~Graph(){ }

int Graph::GetVertPos(const int& vertex)
{
	for (size_t i = 0; i < vertList.size(); i++)
	{
		if (vertList[i] == vertex)
			return i;
	}
	return -1;
}

bool Graph::IsEmpty()
{
	if (vertList.size() != 0)
		return false;
	else
		return true;
}

bool Graph::IsFull()
{
	return (vertList.size() == maxSize);
}

void Graph::InsertVertex(const int& vertex)
{
	if (!IsFull())
		vertList.push_back(vertex);
	else
	{
		cout << "Ошибка! Граф заполнен" << endl; 
		return;
	}
}

void Graph::InsertEdge(const int& vertex1, const int& vertex2, int weight)
{
	if (weight < 1)
	{
		cout << "\nНеверное значение\n";
		return;
	}
	if (GetVertPos(vertex1) != (-1) && GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (adjMatrix[vertPos1][vertPos2] != 0 && adjMatrix[vertPos2][vertPos1] != 0)
		{
			cout << "Ребро уже существует" << endl;
			return;
		}
		else
		{
			adjMatrix[vertPos1][vertPos2] = weight;
		}
	}
	else
	{
		cout << "Граф не имеет одной/двух вершин " << endl;
		return;
	}
}

void Graph::Print()
{
	if (!IsEmpty())
	{
		cout << "Матрица смежности графа: " << endl;
		for (int i = 0; i < vertList.size(); i++)
		{
			cout << vertList[i] << " ";
			for (int j = 0; j < vertList.size(); j++)
				cout << setw(4) << adjMatrix[i][j];
			cout << endl;
		}
	}
	else
		cout << "Граф пуст" << endl;
}

void Graph::eraseLastVert()
{
	if (IsEmpty())
	{
		cout << "\nГраф пуст\n";
		return;
	}
	int n = vertList.size();
	for (int j = 0; j < n; j++)
	{
		adjMatrix[n - 1][j] = 0;
		adjMatrix[j][n - 1] = 0;
	}

	vertList.pop_back();
}

void Graph::eraseEdge(const int& vertex1, const int& vertex2)
{
	if (GetVertPos(vertex1) != (-1) && GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (adjMatrix[vertPos1][vertPos2] == 0 && adjMatrix[vertPos2][vertPos1] == 0)
		{
			cout << "Ребра не существует" << endl;
			return;
		}
		else
		{
			adjMatrix[vertPos1][vertPos2] = 0;
		}
	}
	else
	{
		cout << "Граф не имеет одной/двух вершин " << endl;
		return;
	}
}

int Graph::GetAmountEdges()
{
	int edges = 0;
	for (int i = 0; i < vertList.size(); i++)
		for (int j = 0; j < vertList.size(); j++)
			if (adjMatrix[i][j] > 0)
				edges++;
	return edges;
}

void Graph::drawGraph()
{
	int n = graph.GetAmountVerts();
	for (int i = 0; i < n; i++)
	{
		if (!standView)
			setCoords(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a = adjMatrix[i][j];
			if (a != 0)
				drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			if (a == adjMatrix[j][i] && a != 0)
				drawLine(a, vertC[j].x, vertC[j].y, vertC[i].x, vertC[i].y);
		}
	}
	drawVertex(n);
	glutPostRedisplay();
}

//формирование начальной матрицы
int** Make_TSPMatrix()
{
	int n = graph.GetAmountVerts();
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int elem = graph.getAdjMatrixElem(i, j);
			if (elem == 0 or i == j)
				matrix[i][j] = -1;
			else
				matrix[i][j] = elem;
		}
	}
	cout << "\nПервичная матрица: \n";
	Print_Matrix(matrix);
	return matrix;
}

//функция нахождения минимума 
int* Find_Min(int* line, int n)
{
	int min = 1000000;
	for (int j = 0; j < n; j++)
		if (line[j] >= 0 && line[j] < min)
			min = line[j];
	for (int j = 0; j < n; j++)
		if (line[j] >= 0)
			line[j] -= min;
	return line;
}

void Print_Matrix(int** matrix)
{
	int n = graph.GetAmountVerts();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << matrix[i][j];
		cout << endl;
	}
}

//отвечает за редукцию матрицы
int** Reduct_Matrix(int** oldmatrix)
{
	int** matrix = oldmatrix;
	int n = graph.GetAmountVerts();
	for (int i = 0; i < n; i++)
		matrix[i] = Find_Min(matrix[i], n);
	for (int i = 0; i < n; i++)
	{
		int min = 1000000;
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] >= 0 && matrix[j][i] < min)
				min = matrix[j][i];
		}
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] >= 0)
				matrix[j][i] -= min;
		}
	}
	cout << "\nРедуцированная матрица: \n"; 
	Print_Matrix(matrix);
	return matrix;
}

int** Rebuild_Matrix(int** oldmatrix)
{
	int n = graph.GetAmountVerts();
	int** matrix = Reduct_Matrix(oldmatrix);
	int max = -1;
	int line, column;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				int minLine = 1000000;
				int minColumn = 1000000;
				for (int k = 0; k < n; k++)
				{
					if (matrix[i][k] != -1 && k != j && matrix[i][k] < minLine)
						minLine = matrix[i][k];
				}
				for (int k = 0; k < n; k++)
				{
					if (matrix[k][j] != -1 && k != i && matrix[k][j] < minColumn)
						minColumn = matrix[k][j];
				}
				if (max < minColumn + minLine)
				{
					max = minColumn + minLine;
					line = i;
					column = j;
				}
			}
		}
	}

	pair<int, int> p;
	p.first = line + 1;
	p.second = column + 1;
	Path.push_back(p);

	matrix[line][column] = -1;
	matrix[column][line] = -1;

	for (int i = 0; i < n; i++)
	{
		matrix[line][i] = -1;
		matrix[i][column] = -1;
	}
	cout << endl;
	cout << "Матрица после удаления 0 с наибольшей оценкой: \n";
	Print_Matrix(matrix);
	cout << "\nПромежуточные отрезки путей: ";
	for (int i = 0; i < Path.size(); i++)
		cout << Path[i].first << " -> " << Path[i].second << "   ";
	cout << endl;
	return matrix;
}

//вывод прохождения графа за наименьшую длину
void Print_Result()
{
	int second = Path[0].second;
	int i = 2;
	NewPath.push_back(Path[0].first);
	NewPath.push_back(Path[0].second);
	while (i != graph.GetAmountVerts() + 1)
		for (int j = 1; j < graph.GetAmountVerts(); j++)
			if (Path[j].first == second)
			{
				second = Path[j].second;
				NewPath.push_back(second);
				i++;
			}
	cout << "Ответ: ";
	for (int i = 0; i < NewPath.size(); i++)
	{
		cout << NewPath[i];
		if (i != NewPath.size() - 1)
			cout << " -> ";
	}
}

//описание кнопки, вызывающей решение
void drawButton1()
{
	if (Button_Flag == 1)
		glColor3f(0.8, 0.6, 0.4);
	else
		glColor3f(1.0, 0.8, 0.6);
	glBegin(GL_QUADS);
	glVertex2i(50, WinH - 6 * (WinH / 7) - 20);
	glVertex2i(50, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7, WinH - 6 * (WinH / 7) - 20);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50, WinH - 6 * (WinH / 7) - 20);
	glVertex2i(50, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7, WinH - 6 * (WinH / 7) - 20);
	glEnd();
	string name = "SOLUTION";
	glRasterPos2i(WinW / 15, 0.77 * WinH - 430);
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, name[i]);
}

//описание кнопки, вызывающей печать матрицы
void drawButton2()
{
	if (Button_Flag == 2)
		glColor3f(0.8, 0.6, 0.4);
	else
		glColor3f(1.0, 0.8, 0.6);
	glBegin(GL_QUADS);
	glVertex2i(50 + 140, WinH - 6 * (WinH / 7) - 20);                               
	glVertex2i(50 + 140, WinH - 7 * (WinH / 7));                                    
	glVertex2i(WinW / 7 + 140, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 140, WinH - 6 * (WinH / 7) - 20);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50 + 140, WinH - 6 * (WinH / 7) - 20);
	glVertex2i(50 + 140, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 140, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 140, WinH - 6 * (WinH / 7) - 20);
	glEnd();
	string name = "PRINT MATRIX";
	glRasterPos2i(WinW / 5, 0.77 * WinH - 430);                                  
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, name[i]);
}

//описание кнопки, вызывающей добавление пути
void drawButton3()
{
	if (Button_Flag == 3)
		glColor3f(0.8, 0.6, 0.4);
	else
		glColor3f(1.0, 0.8, 0.6);
	glBegin(GL_QUADS);
	glVertex2i(50 + 280, WinH - 6 * (WinH / 7) - 20);
	glVertex2i(50 + 280, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 280, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 280, WinH - 6 * (WinH / 7) - 20);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50 + 280, WinH - 6 * (WinH / 7) - 20);
	glVertex2i(50 + 280, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 280, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 280, WinH - 6 * (WinH / 7) - 20);
	glEnd();
	string name = "ADD EDGE";
	glRasterPos2i(WinW / 2.9, 0.77 * WinH - 430);
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, name[i]);
}

//описание кнопки, вызывающей удаление пути
void drawButton4()
{
	if (Button_Flag == 4)
		glColor3f(0.8, 0.6, 0.4);
	else
		glColor3f(1.0, 0.8, 0.6);
	glBegin(GL_QUADS);
	glVertex2i(50 + 420, WinH - 6 * (WinH / 7) - 20);
	glVertex2i(50 + 420, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 420, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 420, WinH - 6 * (WinH / 7) - 20);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50 + 420, WinH - 6 * (WinH / 7) - 20);
	glVertex2i(50 + 420, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 420, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 420, WinH - 6 * (WinH / 7) - 20);
	glEnd();
	string name = "DELETE EDGE";
	glRasterPos2i(WinW / 2.1, 0.77 * WinH - 430);
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, name[i]);
}

//описание кнопки, вызывающей вывод наименьшей длины
void drawButton5()
{
	if (Button_Flag == 5)
		glColor3f(0.8, 0.6, 0.4);
	else
		glColor3f(1.0, 0.8, 0.6);
	glBegin(GL_QUADS);
	glVertex2i(50 + 560, WinH - 6 * (WinH / 7) - 20);
	glVertex2i(50 + 560, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 560, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 560, WinH - 6 * (WinH / 7) - 20);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(50 + 560, WinH - 6 * (WinH / 7) - 20);
	glVertex2i(50 + 560, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 560, WinH - 7 * (WinH / 7));
	glVertex2i(WinW / 7 + 560, WinH - 6 * (WinH / 7) - 20);
	glEnd();
	string name = "LENGTH";
	glRasterPos2i(WinW / 1.57, 0.77 * WinH - 430);
	for (int i = 0; i < name.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, name[i]);
}

//изменение цвета круга
void drawCircle(int x, int y, int R)                                       
{
	glColor3f(1.0f, 0.8f, 0.6f);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.2f, 0.2f, 0.3f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

//изменение цвета при нажатии
void drawBorderedCircle(int x, int y, int R)                               
{
	glColor3f(0.8, 0.6, 0.4);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.2, 0.2, 0.3);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

//отвечает за написание текста
void drawText(int text, int x1, int y1)
{
	glColor3f(0.0, 0.0, 0.0);
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(text);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (size_t j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

//отвечает за отрисовку линий
void drawLine(int text, int x0, int y0, int x1, int y1) 
{
	glColor3i(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);

	float vx = x0 - x1;
	float vy = y0 - y1;
	float s = 1.0f / sqrt(vx * vx + vy * vy);
	vx *= s;
	vy *= s;
	x1 = x1 + R * vx;
	y1 = y1 + R * vy;

	glColor3i(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x1 + 10 * (vx + vy), y1 + 10 * (vy - vx));
	glVertex2f(x1 + 10 * (vx - vy), y1 + 10 * (vy + vx));
	glEnd();
}

//отвечает за отрисовку кружков
void drawVertex(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (Mouse_Vert[i])
			drawBorderedCircle(vertC[i].x, vertC[i].y, R);
		else
			drawCircle(vertC[i].x, vertC[i].y, R);
		drawText(i + 1, vertC[i].x, vertC[i].y);
	}

}

void setCoords(int i, int n)
{
	int R_;
	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
		R = 5 * (WinH / 50) / n;
		R_ = WinH / 2 - R - 10;
	}
	else
	{
		R = 5 * (WinW / 50) / n;
		R_ = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * i / n;
	int y1 = R_ * cos(theta) + y0;
	int x1 = R_ * sin(theta) + x0;
	vertC[i].x = x1;
	vertC[i].y = y1;
}

//отвечает за формирование графа
void makeGraph()
{
	standView = false;
	int amountVerts, amountEdges, sourceVertex, targetVertex, edgeWeight;
	cout << "Введите количество вершин: "; cin >> amountVerts;
	cout << "Введите количество ребер: "; cin >> amountEdges;
	for (int i = 1; i <= amountVerts; i++) {

		graph.InsertVertex(i);
	}
	for (int i = 0; i < amountEdges; i++)
	{
		cout << "Исходная вершина: "; cin >> sourceVertex;
		cout << "Конечная вершина: "; cin >> targetVertex;
		cout << "Вес ребра: "; cin >> edgeWeight;
		graph.InsertEdge(sourceVertex, targetVertex, edgeWeight);
	}
	cout << endl;
	graph.Print();
}

bool Salesman_Check(int** matrix)
{
	if (graph.IsEmpty())
		return false;
	for (int i = 0; i < graph.GetAmountVerts(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < graph.GetAmountVerts(); j++)
		{
			if (matrix[i][j] > 0)
				cnt++;
		}
		if (cnt < 1)
			return false;
	}
	return true;
}

int Circle_Check(int x, int y)
{
	for (int i = 0; i < graph.GetAmountVerts(); i++)
		if (pow(x - vertC[i].x, 2) + pow(y - vertC[i].y, 2) <= pow(R, 2))
			return i;
	return -1;
}

void Button_Check(int x, int y)
{
	if (x > 50 && x < WinW / 7 && y < WinH - 6 * (WinH / 7) - 20 && y > WinH - 7 * (WinH / 7))
		Button_Flag = 1;
	else if  (x > (50 + 140) && x < (WinW / 7 + 140) && y < WinH - 6 * (WinH / 7) - 20 && y > WinH - 7 * (WinH / 7))
		Button_Flag = 2;
	else if (x > (50 + 280) && x < (WinW / 7 + 280) && y < WinH - 6 * (WinH / 7) && y > WinH - 7 * (WinH / 7) - 20)
		Button_Flag = 3;
	else if (x > (50 + 420) && x < (WinW / 7 + 420) && y < WinH - 6 * (WinH / 7) && y > WinH - 7 * (WinH / 7) - 20)
		Button_Flag = 4;
	else if (x > (50 + 560) && x < (WinW / 7 + 560) && y < WinH - 6 * (WinH / 7) && y > WinH - 7 * (WinH / 7) - 20)
		Button_Flag = 5;
	else
		Button_Flag = 0;
}

void mouseMove(int x, int y)
{
	y = WinH - y;
	CursorX = x;
	CursorY = y;
	int i = Circle_Check(x, y);
	if (i != -1)
		Mouse_Vert[i] = true;
	else
		for (int j = 0; j < graph.GetAmountVerts(); j++)
			Mouse_Vert[j] = false;
	if (Vert_Move)
	{
		vertC[Moving_Vertex].x = CursorX;
		vertC[Moving_Vertex].y = CursorY;
	}
	Button_Check(x, y);
	glutPostRedisplay();
}

//производит вывод в зависимости от нажатия различных кнопок
void mouseClick(int button, int state, int x, int y)
{
	int j = Circle_Check(x, WinH - y);
	if (Vert_Move)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			Vert_Move = false;
			return;
		}
	}

	if (j != -1)
	{
		standView = true;
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			Vert_Move = true;
			Moving_Vertex = j;
			return;
		}
	}
	if (x >= 50 and x <= (WinW / 7) and y >= (6*(WinH / 7) + 20) and y <= 7 * (WinH / 7))
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			NewPath.clear();
			Path.clear();
			cout << "\nЗадача Коммивояжера:\n";
			int** matrix = Make_TSPMatrix();
			bool checker = Salesman_Check(matrix);
			if (!checker)
			{
				cout << "\nНевозможно решить задачу Коммивояжера\n\n";
				return;
			}
			int n = graph.GetAmountVerts();
			while (Path.size() < n)
				matrix = Rebuild_Matrix(matrix);
			cout << endl;
			Print_Result();
			return;
		}
	}
	if (x >= (50+140) and x <= (WinW / 7+140) and y >= (6 * (WinH / 7) + 20) and y <= 7 * (WinH / 7))
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			graph.Print();
			return;
		}
	}
	if (x >= (50+280) && x <= (WinW / 7+280) && y >= (6 * (WinH / 7)+20) && y <= 7 * (WinH / 7) )
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int sourceVertex, targetVertex, edgeWeight, vertNum;
			cout << "Количество добавляемых путей: "; cin >> vertNum;
			for (int i = 0; i < vertNum; i++)
			{
				cout << "Исходная вершина: "; cin >> sourceVertex;
				cout << "Конечная вершина: "; cin >> targetVertex;
				cout << "Вес ребра: "; cin >> edgeWeight;
				graph.InsertEdge(sourceVertex, targetVertex, edgeWeight);
			}
			return;
		}
	}
	if (x >= (50 + 420) && x <= (WinW / 7 + 420) && y >= (6 * (WinH / 7) + 20) && y <= 7 * (WinH / 7))
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int sourceVertex, targetVertex;
			cout << "Исходная вершина: "; cin >> sourceVertex;
			cout << "Конечная вершина: "; cin >> targetVertex;
			graph.eraseEdge(sourceVertex, targetVertex);
			return;
		}

	}
	if (x >= (50 + 560) && x <= (WinW / 7 + 560) && y >=( 6 * (WinH / 7)+20) && y <= 7 * (WinH / 7))
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			int** matrix = Make_TSPMatrix();
			bool checker = Salesman_Check(matrix);
			if (!checker)
			{
				cout << "\nНевозможно решить задачу Коммивояжера\n\n";
				return;
			}
			int sum = 0;
			for (int i = 0; i < Path.size(); i++)
			{
				int line = Path[i].first - 1;
				int column = Path[i].second - 1;
				sum += graph.getAdjMatrixElem(line, column);
			}
			cout << "\nДлина наименьшего пути = " << sum << endl;
			return;
		}

	}
}

void reshape(int w, int h)
{
	WinW = w;
	WinH = h;
	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

//вывод окна с задачей
void display()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH);
	glViewport(0, 0, WinW, WinH);
	glClearColor(1.0, 0.9, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawButton1();
	drawButton2();
	drawButton3();
	drawButton4();
	drawButton5();
	graph.drawGraph();
	glutSwapBuffers();
}