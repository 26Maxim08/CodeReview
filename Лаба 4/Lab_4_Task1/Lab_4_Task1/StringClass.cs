namespace Lab_4_Task1
{
    public class StringClass : MyClass
    {
        private readonly int Str1;
        private readonly int Str2;
        private readonly int Str3;

        public StringClass(int first, int second, int third, int z, int y, int x)
            : base(first, second, third)
        {
            Str1 = x;
            Str2 = y;
            Str3 = z;
        }

        public StringClass(StringClass other)
            : base(other)
        {
            Str1 = other.Str1;
            Str2 = other.Str2;
            Str3 = other.Str3;
        }

        public int TotalLength()
        {
            return (int)Math.Sqrt(Str1 * Str1 + Str2 * Str2 + Str3 * Str3);
        }

        public override string ToString()
        {
            return $"{base.ToString()}, Str1: {Str1}, Str2: {Str2}, Str3: {Str3}";
        }
    }
}
