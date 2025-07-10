namespace Lab_4_Task1
{
    class Program{
        static void Main()
        {
            Console.WriteLine("Введите три целых числа:");
            if (int.TryParse(Console.ReadLine(), out int x) &&
                int.TryParse(Console.ReadLine(), out int y) &&
                int.TryParse(Console.ReadLine(), out int z))
            {
                TestMyClass(x, y, z);
                TestStringClass(x, y, z);
            }
            else
            {
                Console.WriteLine("Введены неверные данные. " +
                    "Пожалуйста, введите три целых числа.");
            }
            Console.ReadKey();
        }

        static void TestMyClass(int x, int y, int z)
        {
            Console.WriteLine("\nТестирование основного класса MyClass:");
            MyClass myClass = new(x, y, z);
            Console.WriteLine(myClass);
            Console.WriteLine($"Минимальная последняя цифра = " +
                $"{myClass.MinLast()}");

            MyClass myClassCopy = new(myClass);
            Console.WriteLine(myClassCopy);
        }

        static void TestStringClass(int x, int y, int z)
        {
            Console.WriteLine("\nТестирование дочернего класса StringClass:");

            StringClass stringClass = new(x, y, z, z, y, x);
            Console.WriteLine(stringClass);
            Console.WriteLine($"Общая длина строк: {stringClass.TotalLength()}");

            StringClass stringClassCopy = new(stringClass);
            Console.WriteLine(stringClassCopy);
        }
    }
}
