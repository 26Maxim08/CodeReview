namespace Laba_4
{
    public class QuadraticEquation
    {
        private double A;
        private double B;
        private double C;
        public QuadraticEquation(double a, double b, double c)
        {
            A = a;
            B = b;
            C = c;
        }


        public double[] FindRoots()
        {
            double discriminant = B * B - 4 * A * C;

            if (discriminant > 0)
            {
                double root1 = (-B + Math.Sqrt(discriminant)) / (2 * A);
                double root2 = (-B - Math.Sqrt(discriminant)) / (2 * A);
                return [root1, root2];
            }
            else if (discriminant == 0)
            {
                double root = -B / (2 * A);
                return [root];
            }
            else
            {
                return [];
            }
        }
        public override string ToString()
        {
            return $"Уравнение: {A}x^2 + {B}x + {C} = 0";
        }
        public static QuadraticEquation operator ++(QuadraticEquation eq)
        {
            eq.A++;
            eq.B++;
            eq.C++;
            return eq;
        }

        public static QuadraticEquation operator --(QuadraticEquation eq)
        {
            eq.A--;
            eq.B--;
            eq.C--;
            return eq;
        }

        public static implicit operator double(QuadraticEquation eq)
        {
            return eq.B * eq.B - 4 * eq.A * eq.C;
        }

        public static explicit operator bool(QuadraticEquation eq)
        {
            return (eq.B * eq.B - 4 * eq.A * eq.C) >= 0;
        }

        public static bool operator ==(QuadraticEquation eq1, QuadraticEquation eq2)
        {
            return eq1.A == eq2.A && eq1.B == eq2.B && eq1.C == eq2.C;
        }
        public static bool operator !=(QuadraticEquation eq1, QuadraticEquation eq2)
        {
            return !(eq1 == eq2);
        }
    }
}
