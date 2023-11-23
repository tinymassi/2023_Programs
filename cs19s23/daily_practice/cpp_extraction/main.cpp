#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <cstring>
#include <limits>
#include <algorithm>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

std::string encrypt (std::string string) {
    unsigned char ciphertext[128];  // an array of size 128 elementsused to store result of encryption
    const unsigned char key[] = "0123456789abcdef";  // const unsigned char bc it relates to binary data its const bc this data shouldnt be modified
    const unsigned char iv[] = "abcdefghijklmnop";  // This helps to randomize the encryption process
    const unsigned char* binary_string = reinterpret_cast<const unsigned char*>(string.c_str());
    EVP_CIPHER_CTX *ctx;  // a structure used to maintain information for cryptography such as the decryption or encryption algorithm
    std::string encrypted_string;

    ctx = EVP_CIPHER_CTX_new();  // allocated memory for a new EVP_CIPHER structure & returns pointer to created struct
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cfb(), NULL, key, iv);  // initializes encryption operation
    // EVP_aes_128_cfb() is a function that creates an EVP_CYPHER object representing the algorithm used for encryption for key length of 128 bits

    int len;  // used to store the length of the outuput after encryption process
    int ciphertext_length;  // used to store the length of the ciphertext (encrypted data) after encryption process

    EVP_EncryptUpdate(ctx, ciphertext, &len, binary_string, string.size());  // updates the encryption context ('ctx') by taking the password, and producing
                                                                             // the encrypted output in the ciphertext buffer. &len is used to track # of bytes in update.

    ciphertext_length = len;  // updates the cipher text length after EVP update

    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);  // this produces the final encrypted output.

    ciphertext_length += len;  // again updating the cipher text length

    EVP_CIPHER_CTX_free(ctx);  // this deallocates the memory that was created with the EVP_CIPHER_CTX pointer structure

    encrypted_string.assign(reinterpret_cast<const char*>(ciphertext), ciphertext_length);

    return encrypted_string;
}

std::string decrypt (std::string encrypted_string) {
    unsigned char decryptedtext[128];  // an array of size 128 elementsused to store result of encryption
    const unsigned char key[] = "0123456789abcdef";  // const unsigned char bc it relates to binary data its const bc this data shouldnt be modified
    const unsigned char iv[] = "abcdefghijklmnop";  // This helps to randomize the encryption process
    const unsigned char* binary_encrypted_string = reinterpret_cast<const unsigned char*>(encrypted_string.c_str());
    std::string decrypted_string;
    EVP_CIPHER_CTX* ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cfb(), NULL, key, iv);

    int len;
    int decryptedtext_length;

    EVP_DecryptUpdate(ctx, decryptedtext, &len, binary_encrypted_string, encrypted_string.size());
    decryptedtext_length = len;

    EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

    decryptedtext_length += len;

    decrypted_string.assign(reinterpret_cast<const char*>(decryptedtext), decryptedtext_length);

    return decrypted_string;
}

void saveDataToFile(const std::vector<std::pair<std::string, std::string>>& container,const std::string& file_name) {
    std::ofstream save_to_file (file_name, std::ios::app);
    if (save_to_file.is_open()) {
        for (int i = 0; i < container.size(); i++) {
            save_to_file << encrypt("START") << '\n';
            save_to_file << encrypt(container[i].first) << '\n';
            save_to_file << encrypt(container[i].second) << '\n';
            save_to_file << encrypt("END") << '\n';
        }
        save_to_file.close();
        std::cout << GREEN << "Data successfully transferred to " << file_name << RESET << '\n';
    } else {
        std::cerr << "Unable to open file: " << file_name << '\n';
    }
}

void loadDataFromFile (std::vector<std::pair<std::string, std::string>>& container, std::string& file_name) {
    std::ifstream take_from_file (file_name);
    std::vector <std::pair<int, std::string>> file_data_container;
    std::cout << GREEN << "DECRYPTED MESSAGE: " << RESET << '\n';
    if (take_from_file.is_open()) {
        std::string line{};
        std::string entry{};
        int password{};
        int loop_tracker = 0;
        while (std::getline(take_from_file, line)) {
            line = decrypt(line);
            if (line != "START" && line != "END" && line != "") {
                if (std::all_of(line.begin(), line.end(), ::isdigit)) {
                    password = std::stoi(line);
                } else {
                    entry += line;
                    entry += '\n';
                }
            } else if (line == "END") {
                file_data_container.push_back(std::make_pair(password, entry));
                entry = "";
            }
            loop_tracker++;
        }
        take_from_file.close();
    } else {
        std::cerr << "Unable to open file: " << file_name << std::endl;
    }

    for (int i = 0; i < file_data_container.size(); i++) {
        std::cout << "[KEY]: " << file_data_container[i].first << '\n';
        std::cout << "[VALUE]: " << file_data_container[i].second << '\n';
    }
}

int main() {

    std::vector<std::pair<std::string, std::string>> container;
    std::string text_file_name = "text_file.txt";
    std::string terminal_input{};
    std::string text_entry{};
    std::string password{};
    bool check1 = true;

    while (check1) {
        std::cout << "INSERT PASSWORD INTO VECTOR: " << '\n';
        std::cin >> password;
        if (password == "stop" || password == "Stop") {
            break;
        }
        std::cout << "INSERT ENTRY INTO VECTOR: " << '\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (check1) {
            std::getline(std::cin, terminal_input);
            if (terminal_input == "next" || terminal_input == "Next") {
                break;
            }
            text_entry += terminal_input;
            text_entry += "\n";
        }
        container.push_back(std::make_pair(password, text_entry));
        text_entry = "";
        std::cout << "Are you done?" << '\n';
        std::cout << "> ";
        std::cin >> terminal_input;
        if (terminal_input == "yes" || terminal_input == "Yes") {
            break;
        }
    }

    saveDataToFile(container, text_file_name);
    loadDataFromFile(container, text_file_name);

    return{};
}