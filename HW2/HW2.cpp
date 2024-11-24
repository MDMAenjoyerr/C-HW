#include <iostream>
#include <vector>
#include <algorithm>

void print_result(int correct_positions, int correct_numbers) {
    std::cout << "����� �� ����� ������: " << correct_positions << "\n";
    std::cout << "����� ����������, �� �� �� ����� ������: " << correct_numbers << "\n";
}

std::pair<int, int> check_guess(const std::vector<int>& secret, const std::vector<int>& guess) {
    int correct_positions = 0;
    int correct_numbers = 0;

    std::vector<int> secret_count(7, 0);
    std::vector<int> guess_count(7, 0);

    for (int i = 0; i < 4; ++i) {
        if (secret[i] == guess[i]) {
            ++correct_positions;
        }
        else {
            ++secret_count[secret[i]];
            ++guess_count[guess[i]];
        }
    }

    for (int i = 1; i <= 6; ++i) {
        correct_numbers += std::min(secret_count[i], guess_count[i]);
    }

    return { correct_positions, correct_numbers };
}

int main() {
    std::cout << "����� ���������� � ���� ��� 2-� �������!\n";
    std::cout << "����� 1: ������� ���������� �� 4 ����� �� 1 �� 6 (������): ";

    std::vector<int> secret(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> secret[i];
        if (secret[i] < 1 || secret[i] > 6) {
            std::cout << "����� ������ ���� �� 1 �� 6. ���������� ��� ���.\n";
            return 1;
        }
    }

    std::cout << "\033[2J\033[1;1H"; // ������� ����� (�������� � ���������)

    std::cout << "����� 2: � ��� ���� 6 �������, ����� ������� ����������!\n";

    for (int attempt = 1; attempt <= 6; ++attempt) {
        std::cout << "������� " << attempt << ": ������� ���������� �� 4 �����: ";
        std::vector<int> guess(4);
        for (int i = 0; i < 4; ++i) {
            std::cin >> guess[i];
            if (guess[i] < 1 || guess[i] > 6) {
                std::cout << "����� ������ ���� �� 1 �� 6. ���������� ��� ���.\n";
                --attempt;
                goto retry;
            }
        }

        auto [correct_positions, correct_numbers] = check_guess(secret, guess);

        print_result(correct_positions, correct_numbers);

        if (correct_positions == 4) {
            std::cout << "�����������! �� ������� ����������!\n";
            return 0;
        }
    retry:;
    }

    std::cout << "� ���������, �� �� ������� ����������. ����� � ��������� ���!\n";

    return 0;
}
