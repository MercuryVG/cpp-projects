#include <iostream>

void insert_element(int queue[], const int length, int& front, int& back);
void delete_element(int queue[], int& front, int& back);
void display_queue(int queue[], const int front, const int back);

int main()
{
    int queue[100];
    int length = 100;
    int front = -1;
    int back = -1;

    int choice;
    std::cout << "1) Insert element in queue" << std::endl;
    std::cout << "2) Delete element from queue" << std::endl;
    std::cout << "3) Display all the elements of queue" << std::endl;
    std::cout << "4) Exit" << std::endl;

    do {
        try
        {
            std::cout << "Enter your choice : ";
            std::cin >> choice;
            if (std::cin.fail())
            {
                throw 1;
            }
            switch (choice) {
            case 1: insert_element(queue, length, front, back);
                break;
            case 2: delete_element(queue, front, back);
                break;
            case 3: display_queue(queue, front, back);
                break;
            case 4: std::cout << "Exit" << std::endl;
                break;
            default: std::cout << "Invalid choice" << std::endl;
            }
        }
        catch (int error)
        {
            std::cout << "Use only integer numbers!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while (choice != 4);
       

    return 0;
}

void insert_element(int queue[], const int length, int &front, int &back)
{
    int value;
    if(back == length - 1)
    {
        std::cout << "Cannot fit more in queue, need to delete one element" << std::endl;
        return;
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        try
        {
            std::cout << "Write number to insert it in queue: ";
            std::cin >> value;
            if(std::cin.fail())
            {
                throw 1;
            }
            std::cout << std::endl;
            back++;
            queue[back] = value;
        }
        catch(int error)
        {
            std::cout << "Use only integer numbers!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void delete_element(int queue[], int &front, int &back)
{
    if(front == -1 || front > back)
    {
        std::cout << "Cannot delete element. No elements int queue" << std::endl;
        return;
    }
    else
    {
        std::cout << "Deleted element is: " << queue[front] << std::endl;
        front++;
    }
}

void display_queue(int queue[], const int front, const int back)
{
    if(front == -1)
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    else
    {
        std::cout << "Queue elements are: ";
        for(int i = front; i <= back; i++)
        {
            std::cout << queue[i] << " ";
        }
        std::cout << std::endl;
    }
}