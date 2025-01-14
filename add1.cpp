void add(float x)
{
    static float y = 0.0;
    extern float z;
    y = y + 2;
    z = x + y;
}