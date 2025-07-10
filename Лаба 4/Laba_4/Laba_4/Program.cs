namespace Laba_4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите первый коэфициент (A): ");
            string A = Console.ReadLine();

            Console.Write("Введите второй коэфициент (B): ");
            string B = Console.ReadLine();

            Console.Write("Введите третий коэфициент (C): ");
            string C = Console.ReadLine();

            if (double.TryParse(A, out double x) && 
                double.TryParse(B, out double y) && 
                double.TryParse(C, out double z))
            {
                
                Console.WriteLine();
                QuadraticEquation equation1 = new QuadraticEquation(x, y, z);
                Console.WriteLine(equation1.ToString());
                double[] roots1 = equation1.FindRoots();
                Console.WriteLine("Корни: " + string.Join("; ", roots1));
                Console.WriteLine("----------------------------");

                
                Console.WriteLine("Перед выполнением операции ++: " + 
                    equation1.ToString());
                equation1++;
                Console.WriteLine("После выполнения операции ++: " + 
                    equation1.ToString());
                Console.WriteLine("----------------------------");
                
                Console.WriteLine("Перед выполнением операции --: " + 
                    equation1.ToString());
                equation1--;
                Console.WriteLine("После выполнения операции --: " + 
                    equation1.ToString());
                Console.WriteLine("----------------------------");

                
                double Discriminant = equation1;
                Console.WriteLine("Дискременант: " + Discriminant);
                Console.WriteLine("----------------------------");
                
                bool Roots = (bool)equation1;
                Console.WriteLine("У этого уравнения есть корни: " + Roots);
                Console.WriteLine("----------------------------");

                
                QuadraticEquation equation2 = new QuadraticEquation(x, y, z);
                Console.WriteLine(equation1 + " == " + equation2 + " : " + 
                    (equation1 == equation2));
                Console.WriteLine("----------------------------");
                Console.WriteLine(equation1 + " != " + equation2 + " : " + 
                    (equation1 != equation2));
            }
            else
            {
                Console.WriteLine("Введены некорректные данные");
            }
            Console.ReadKey();
        }
    }
}
