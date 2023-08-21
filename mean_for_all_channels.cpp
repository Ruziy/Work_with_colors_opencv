#include <opencv2/opencv.hpp>

int main() {
    // ������ �����������
    cv::Mat image = cv::imread("input.jpg");

    // ���������� ������ red
    std::vector<cv::Mat> channels;
    cv::split(image, channels);
    cv::Mat redChannel = channels[2];

    // ��������� ���������
    cv::Mat binaryImage;
    cv::threshold(redChannel, binaryImage, 128, 255, cv::THRESH_BINARY);

    // ���������� �������� ��������
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binaryImage, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // �������� ����� ������ � ������ ��������
    cv::Mat mask = cv::Mat::zeros(image.size(), CV_8UC1);
    cv::drawContours(mask, contours, 0, cv::Scalar(255), cv::FILLED);

    // ���������� ����� � ��������� �����������
    cv::Mat result;
    image.copyTo(result, mask);

    // ���������� ����������
    cv::imwrite("output.jpg", result);

    return 0;
}