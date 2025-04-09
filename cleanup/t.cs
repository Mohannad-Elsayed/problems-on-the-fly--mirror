using System;
using System.Linq;

class Program
{
    static int MaxElementsToRemove(int n, int[] arr)
    {
        // ترتيب العناصر تنازلياً
        arr = arr.OrderByDescending(x => x).ToArray();

        int res = 0;

        // عد العناصر التي هي أكبر من العنصر الأخير
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > arr[n - 1])
            {
                res++;
            }
        }
        return res;
    }

    static void Main(string[] args)
    {
        // قراءة عدد العناصر
        Console.WriteLine("أدخل عدد العناصر:");
        int n = int.Parse(Console.ReadLine());

        // قراءة العناصر
        Console.WriteLine("أدخل العناصر:");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = int.Parse(Console.ReadLine());
        }

        int res = MaxElementsToRemove(n, arr);

        // طباعة النتيجة
        Console.WriteLine("عدد العناصر الأكبر من العنصر الأخير: " + res);
    }
}
