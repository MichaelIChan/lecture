为双端队列和随机队列编写通用数据类型。 这项任务的目的是使用数组和链接列表实现基本数据结构，并向您介绍泛型和迭代器。

出队。 双端队列或双端队列（发音为“ deck”）是堆栈和队列的概括，支持从数据结构的正面或背面添加和删除项。
创建实现以下API的通用数据类型Deque：

public class Deque<Item> implements Iterable<Item> {

    // construct an empty deque
    public Deque()

    // is the deque empty?
    public boolean isEmpty()

    // return the number of items on the deque
    public int size()

    // add the item to the front
    public void addFirst(Item item)

    // add the item to the back
    public void addLast(Item item)

    // remove and return the item from the front
    public Item removeFirst()

    // remove and return the item from the back
    public Item removeLast()

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator()

    // unit testing (required)
    public static void main(String[] args)

}

角落案例。 将以下异常情况抛出指定的异常:
如果客户端使用空参数调用addFirst（）或addLast（），则抛出IllegalArgumentException。
如果双端队列为空时客户端调用removeFirst（）或removeLast，则抛出java.util.NoSuchElementException。
如果在没有更多项可返回时客户端在迭代器中调用next（）方法，则抛出java.util.NoSuchElementException。
如果客户端在迭代器中调用remove（）方法，则引发UnsupportedOperationException。

单元测试。 
您的main（）方法必须直接调用每个公共构造函数和方法，以帮助验证它们是否按规定工作（例如，通过将结果打印到标准输出中）。

性能要求。 
您的双端队列实施必须在恒定的最坏情况下支持每个双端队列操作（包括构造）。 
包含n个项的双端队列必须最多使用48n + 192字节的内存。 
此外，您的迭代器实现必须在最坏的情况下始终支持每个操作（包括构造）。

随机队列。 
随机队列类似于堆栈或队列，不同之处在于，除去的项目是在数据结构中的项目之间随机随机选择的。 
创建实现以下API的通用数据类型RandomizedQueue：

public class RandomizedQueue<Item> implements Iterable<Item> {

    // construct an empty randomized queue
    public RandomizedQueue()

    // is the randomized queue empty?
    public boolean isEmpty()

    // return the number of items on the randomized queue
    public int size()

    // add the item
    public void enqueue(Item item)

    // remove and return a random item
    public Item dequeue()

    // return a random item (but do not remove it)
    public Item sample()

    // return an independent iterator over items in random order
    public Iterator<Item> iterator()

    // unit testing (required)
    public static void main(String[] args)

}

迭代器。 每个迭代器必须以统一的随机顺序返回项目。 同一随机队列中两个或多个迭代器的顺序必须相互独立。 每个迭代器必须保持自己的随机顺序。

角落案例。 将以下异常情况抛出指定的异常：
如果客户端使用空参数调用enqueue（），则抛出IllegalArgumentException。
如果客户端在随机队列为空时调用sample（）或dequeue（），则抛出java.util.NoSuchElementException。
如果在没有更多项可返回时客户端在迭代器中调用next（）方法，则抛出java.util.NoSuchElementException。
如果客户端在迭代器中调用remove（）方法，则引发UnsupportedOperationException。

单元测试。 您的main（）方法必须直接调用每个公共构造函数和方法，以验证它们是否按规定工作（例如，通过将结果打印到标准输出中）。

性能要求。 您的随机队列实现必须在固定的摊销时间内支持每个随机队列操作（除了创建迭代器之外）。
也就是说，对于某些常数c，在最坏的情况下，m个随机队列操作的任何混合序列（从空队列开始）必须最多执行cm步。
包含n个项的随机队列最多必须使用48n + 192字节的内存。 另外，您的迭代器实现必须在最坏的情况下始终支持next（）和hasNext（）操作。
并在线性时间内进行构造； 您可能（并且将需要）为每个迭代器使用线性数量的额外内存。

客户。 编写一个客户端程序Permutation.java，它使用整数k作为命令行参数。
使用StdIn.readString（）从标准输入读取字符串序列； 并精确地均匀地打印其中的k个。 最多打印一次序列中的每个项目。

您的程序必须实现以下API：
public class Permutation {
    public static void main(String[] args)
}

命令行参数。 您可以假设0≤k≤n，其中n是标准输入上的字符串数。 请注意，您没有得到n。

性能要求。 排列的运行时间必须与输入大小成线性关系。
您只能使用固定数量的内存，以及一个最大大小为n的Deque或RandomizedQueue对象。
（对于额外的挑战和少量的额外功劳，请仅使用一个最大大小最大为k的Deque或RandomizedQueue对象。）

网络提交。 提交一个仅包含RandomizedQueue.java，Deque.java和Permutation.java的.zip文件。
除了StdIn，StdOut，StdRandom，java.lang，java.util.Iterator和java.util.NoSuchElementException中的函数外，您的提交不能调用库函数。
尤其不要使用java.util.LinkedList或java.util.ArrayList。