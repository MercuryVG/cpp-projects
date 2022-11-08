#include <iostream>
#include<cstdlib>

int get_the_biggest_element(float prices[], const int start_index, const int number_of_days);
void append_one_cell(int **arr, int length);

int main()
{
    srand((unsigned)time(NULL));

    float total_cash = 0;
    int number_of_days, length_of_hair;
    std::cout << "Enter number of days: ";
    std::cin >> number_of_days;
    std::cout << std::endl;
    std::cout << "Enter initial hair length: ";
    std::cin >> length_of_hair;
    std::cout << std::endl;
    std::cout << "Generate 10 prices with random shift from 2.5 to 3.5 to simulate market activity:" << std::endl;

    int hair_growth_speed = 1;
    float* prices = new float[number_of_days];

    for (int i = 0; i < number_of_days; i++)
    {
        prices[i] = 2.5 + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (3.5 - 2.5));

        std::cout << prices[i] << std::endl;
    }
    std::cout << std::endl;

    int* buying_plan = new int[1];
    int start_index = 0;
    int buying_plan_elements = 0;
    while (start_index != number_of_days - 1)
    {
        buying_plan[buying_plan_elements] = get_the_biggest_element(prices, start_index, number_of_days);
        start_index = buying_plan[buying_plan_elements];
        if(start_index == 0)
        {
            start_index++;
        }
        buying_plan_elements++;
        append_one_cell(&buying_plan, buying_plan_elements);
    }
    std::cout << "Chosen days by index:" << std::endl;
    for (int i = 0; i < buying_plan_elements; i++)
    {
        std::cout << buying_plan[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Results:" << std::endl;
    int buying_plan_iterator = 0;
    for(int i = 0; i < number_of_days; i++)
    {
        length_of_hair++;
        if(i <= 9)
        {
            if (buying_plan[buying_plan_iterator] == i)
            {
                total_cash += length_of_hair * prices[buying_plan[buying_plan_iterator]];
                std::cout << "Sold: " << length_of_hair << " for: " << length_of_hair * prices[buying_plan[buying_plan_iterator]] << std::endl;
                buying_plan_iterator++;
                length_of_hair = 0;

            }
        }
    }
    std::cout << "Total money earned: ";
    std::cout << total_cash << std::endl;

    system("pause");


    return 0;
}

int get_the_biggest_element(float prices[], int start_index, const int number_of_days)
{
    int element = 0;
    if(start_index == 0)
    {
        element = start_index;
    }
    else
    {
        start_index++;
        element = start_index;
    }

    for(int i = start_index; i < number_of_days; i++)
    {
        if(prices[i] > prices[element])
        {
            element = i;
        }
    }
    return element;
}

void append_one_cell(int **arr, int length)
{
    int* new_arr = new int[length + 1];
    for (int i = 0; i < length; i++)
    {
        new_arr[i] = (*arr)[i];
    }
    delete[] *arr;
    *arr = new_arr;
}