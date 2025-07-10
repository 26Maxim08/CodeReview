namespace Lab_4_Task1
{
    public class MyClass{
        private readonly int _first;
        private readonly int _second;
        private readonly int _third;

        public MyClass(int first, int second, int third)
        {
            _first = first;
            _second = second;
            _third = third;
        }

        public MyClass(MyClass other)
        {
            _first = other._first;
            _second = other._second;
            _third = other._third;
        }

        public int MinLast()
        {
            static int GetLastDigit(int number) => Math.Abs(number) % 10;
            return Math.Min(Math.Min(GetLastDigit(_first), 
                GetLastDigit(_second)), GetLastDigit(_third));
        }

        public override string ToString()
        {
            return $"First: {_first}, Second: {_second}, Third: {_third}";
        }
    }
}
