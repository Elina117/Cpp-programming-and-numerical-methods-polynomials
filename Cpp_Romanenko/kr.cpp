using System;
namespace Chiz
{
 class Program
 {
 static float eps = 1e-6f;
 static double J(double a, double b, double x, int func, out int N)
 {
 double J2N = -1;//значение вычисленное по формуле
 double JN;//значение для вычисления погрешности
 int n = 1;// количество разбиений

 do
 {
 JN = J2N;
 double interval = (b - a) / n;
 double[] t = new double[n + 1]; // количество отрезков
 for (int i = 0; i < n + 1; ++i)
 {
 t[i] = a + i * interval;
 }
 J2N = 0;
 double h;
 switch (func)
 {
 case 0:
 for (int i = 0; i < n; ++i)
 {
 h = t[i + 1] - t[i];
 J2N += h * ((F(t[i], x) + F(t[i + 1], x)) / 2f);//формула трапеции
 }
 break;
 case 1:
 for (int i = 0; i < n; ++i)
 {
 h = t[i + 1] - t[i];
 J2N += (h / 6) * (F(t[i], x) + 4 * F((t[i] + t[i + 1]) / 2f, x) + F(t[i + 1],
x));//формула Симпсона
 }
 break;
 case 2:
 for (int i = 0; i < n; ++i)
11
 {
 h = t[i + 1] - t[i];
 J2N += (h / 2) * (F(t[i] + h / 2 * (1 - 1 / Math.Sqrt(3)), x) + F(t[i] + h /
2 * (1 + 1 / Math.Sqrt(3)), x));//формула Гаусса
 }
 break;
 case 3:
 for (int i = 0; i < n; ++i)
 {
 h = t[i + 1] - t[i];
 J2N += F((t[i] + t[i + 1]) / 2f, x) * h;//формула центральных
прямоугольников
 }
 break;
 case 4:
 for (int i = 0; i < n; ++i)
 {
 h = t[i + 1] - t[i];
 J2N += F(t[i], x) * h;// формула левых прямоугольников
 }
 break;
 case 5:
 for (int i = 1; i < n + 1; ++i)
 {
 h = t[i] - t[i - 1];
 J2N += F(t[i], x) * h;// формула правых прямоугольников
 }
 break;
 }
 J2N = 2 / Math.Sqrt(Math.PI) * J2N;
12
 n *= 2;//разбиение берем только четное
 } while (!(Math.Abs(JN - J2N) < eps));
 N = n / 2;//количество разбиений
 return J2N;
 }
 public const double E = 2.7182818284590451;
 static double F(double t, double x)
 {
 return Math.Pow(E, ((-1)*(t*t)));//интеграл
 }
 static void Main(string[] args)
 {
 double a = 0, b = 2;
 double[] J0 = new double[11] { 0, 0.222703, 0.428393, 0.603856,
 0.742102, 0.842702, 0.910314, 0.952285,0.976349, 0.989091, 0.995322 };//
значения функции из первого задания
 for (int func = 0; func < 6; ++func)
 {
 switch (func)
 {
 case 0:
 Console.Write("\nTrapeciya\n");
 break;
 case 1:
 Console.Write("\nSimpson\n");
 break;
 case 2:
 Console.Write("\nGauss\n");
 break;
 case 3:
13
 Console.Write("\nCentral\n");
 break;
 case 4:
 Console.Write("\nLeft\n");
 break;
 case 5:
 Console.Write("\nRight\n");
 break;
 }
 Console.Write("X\tJ_0(x)\tJ_N(x)\tJ_0(x)-J_N(x)\t\tN\n");//столбцы
 int j = 0;
 for (double x = a; x <= b; x += 0.2)
 {
 Console.Write($"{Math.Round(x, 4)}\t");
 Console.Write($"{Math.Round(J0[j], 4)}\t");
 double JN = J(a, b, x, func, out int N);
 Console.Write($"{Math.Round(JN, 4)}\t");
 Console.Write($"{J0[j++] - JN:F20}\t");
 Console.Write($"{N}\n");
 }
 }
 Console.Write("\nZamechanie Levyh\n");
 Console.Write("X\tJ_0(x)\tJ_N(x)\tJ_0(x)-J_N(x)\t\tN\n");
 int i = 0;
 for (double x = a; x <= b; x += 0.2)
 {
 Console.Write($"{Math.Round(x, 4)}\t");
 Console.Write($"{Math.Round(J0[i], 4)}\t");
 double J2N = 0;
14
 int n = 1024;
 double interval = (b - a) / n;
 double[] t = new double[n + 1];
 for (int j = 0; j < n + 1; ++j)
 {
 t[j] = a + j * interval;
 }
 double h;
 for (int j = 0; j < n; ++j)
 {
 h = t[j + 1] - t[j];
 J2N += F(t[j], x) * h;
 }
 J2N = 2 / Math.Sqrt(Math.PI) * J2N;
 Console.Write($"{J2N:F4}\t");
 Console.Write($"{J0[i++] - J2N:F20}\t");
 Console.Write($"{n}\n");
 }
 }
 }
}