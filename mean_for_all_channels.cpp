#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // �������� �����������
    cv::Mat image = cv::imread("image.jpg");

    // �������� �� �������� �������� �����������
    if (image.empty())
    {
        std::cout << "�� ������� ��������� �����������." << std::endl;
        return -1;
    }

    // ��������� ����������� �� ��������� �������� ������
    std::vector<cv::Mat> channels;
    cv::split(image, channels);

    // ���������� �������� �������� �� ������� ��������� ������
    double blue_mean = cv::mean(channels[0])[0];
    double green_mean = cv::mean(channels[1])[0];
    double red_mean = cv::mean(channels[2])[0];

    // ����� ������� �������� ������
    std::cout << "������� ���� ����������� (BGR): " << blue_mean << ", " << green_mean << ", " << red_mean << std::endl;

    return 0;
}