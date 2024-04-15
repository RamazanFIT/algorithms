from decimal import Decimal, getcontext

def solve():

    getcontext().prec = 1000  

    def get():
        return map(Decimal, input_file.readline().split())

    def put(*args):
        output_file.write(' '.join(map(str, args)) + '\n')

    with open('intersec1.in', 'r') as input_file, open('intersec1.out', 'w') as output_file:
        a1, b1, c1, a2, b2, c2 = get()

        if a1 == a2 and b1 == b2 and c1 == c2:
            x = 1
            y = (-c1 - a1*x) / b1 
            put(x, y)
            exit(0)
             
            
        a = c2 * b1 - c1 * b2
        b = a1 * b2 - a2 * b1
        x = a / b
        y = -((a1 * x + c1) / b1)

        put(x, y)

solve()
