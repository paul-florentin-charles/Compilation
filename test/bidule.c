int g(float a, int b)
{
  int r;
  r = a;
  a = a + b;
  r = r + a;
  return r;
}

void f()
{
  float a;
  int b;
  int c;
  a = 1.5;
  b = 2;
  c = g(a, b);
}

int main()
{
  int a;
  float b;
  a = 2;
  b = 3.4;
  int c;
  c = g(b, a);
  return c;
}
