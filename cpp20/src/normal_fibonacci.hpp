class Fibonacci
{
public:
    int next() {
        if (a == -1) {
            a = 0;
            b = 1;
            return 0;
        }

        int next = b;
        b = a + b;
        a = b - a;
        return next;
    }

private:
    int a = -1;
    int b = 0;
};
