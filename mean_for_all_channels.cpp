#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // Загрузка изображения
    cv::Mat image = cv::imread("image.jpg");

    // Проверка на успешную загрузку изображения
    if (image.empty())
    {
        std::cout << "Не удалось загрузить изображение." << std::endl;
        return -1;
    }

    // Разбиение изображения на отдельные цветовые каналы
    std::vector<cv::Mat> channels;
    cv::split(image, channels);

    // Вычисление среднего значения по каждому цветовому каналу
    double blue_mean = cv::mean(channels[0])[0];
    double green_mean = cv::mean(channels[1])[0];
    double red_mean = cv::mean(channels[2])[0];

    // Вывод средних значений цветов
    std::cout << "Средний цвет изображения (BGR): " << blue_mean << ", " << green_mean << ", " << red_mean << std::endl;

    return 0;
}