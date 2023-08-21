#include <opencv2/opencv.hpp>

int main() {
    // Чтение изображения
    cv::Mat image = cv::imread("input.jpg");

    // Извлечение канала red
    std::vector<cv::Mat> channels;
    cv::split(image, channels);
    cv::Mat redChannel = channels[2];

    // Пороговая обработка
    cv::Mat binaryImage;
    cv::threshold(redChannel, binaryImage, 128, 255, cv::THRESH_BINARY);

    // Нахождение контуров объектов
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binaryImage, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Создание маски только с нужным контуром
    cv::Mat mask = cv::Mat::zeros(image.size(), CV_8UC1);
    cv::drawContours(mask, contours, 0, cv::Scalar(255), cv::FILLED);

    // Применение маски к исходному изображению
    cv::Mat result;
    image.copyTo(result, mask);

    // Сохранение результата
    cv::imwrite("output.jpg", result);

    return 0;
}