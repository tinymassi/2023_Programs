#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <cstring>

std::string encrypt (std::string password) {
    unsigned char ciphertext[128];  // an array of size 128 elementsused to store result of encryption
    const unsigned char key[] = "0123456789abcdef";  // const unsigned char bc it relates to binary data its const bc this data shouldnt be modified
    const unsigned char iv[] = "abcdefghijklmnop";  // This helps to randomize the encryption process
    const unsigned char* binary_password = reinterpret_cast<const unsigned char*>(password.c_str());
    EVP_CIPHER_CTX *ctx;  // a structure used to maintain information for cryptography such as the decryption or encryption algorithm
    std::string encrypted_password;

    ctx = EVP_CIPHER_CTX_new();  // allocated memory for a new EVP_CIPHER structure & returns pointer to created struct
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cfb(), NULL, key, iv);  // initializes encryption operation
    // EVP_aes_128_cfb() is a function that creates an EVP_CYPHER object representing the algorithm used for encryption for key length of 128 bits

    int len;  // used to store the length of the outuput after encryption process
    int ciphertext_length;  // used to store the length of the ciphertext (encrypted data) after encryption process

    EVP_EncryptUpdate(ctx, ciphertext, &len, binary_password, password.size());  // updates the encryption context ('ctx') by taking the password, and producing
                                                                                 // the encrypted output in the ciphertext buffer. &len is used to track # of bytes in update.

    ciphertext_length = len;  // updates the cipher text length after EVP update

    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);  // this produces the final encrypted output.

    ciphertext_length += len;  // again updating the cipher text length

    EVP_CIPHER_CTX_free(ctx);  // this deallocates the memory that was created with the EVP_CIPHER_CTX pointer structure

    encrypted_password.append(reinterpret_cast<const char*>(ciphertext), ciphertext_length);

    // for (int i = 0; i < strlen(reinterpret_cast<const char *> (binary_password)); i++) {
    //     encrypted_password += binary_password[i];
    // }

    return encrypted_password;
}

std::string decrypt (std::string encrypted_password) {
    unsigned char decryptedtext[128];  // an array of size 128 elementsused to store result of encryption
    const unsigned char key[] = "0123456789abcdef";  // const unsigned char bc it relates to binary data its const bc this data shouldnt be modified
    const unsigned char iv[] = "abcdefghijklmnop";  // This helps to randomize the encryption process
    const unsigned char* binary_encrypted_password = reinterpret_cast<const unsigned char*>(encrypted_password.c_str());
    std::string decrypted_password;
    EVP_CIPHER_CTX* ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cfb(), NULL, key, iv);

    int len;
    int decryptedtext_length;

    EVP_DecryptUpdate(ctx, decryptedtext, &len, binary_encrypted_password, encrypted_password.size());
    decryptedtext_length = len;

    EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

    decryptedtext_length += len;

    decrypted_password.append(reinterpret_cast<const char*>(decryptedtext), decryptedtext_length);

    return decrypted_password;
}

void saveDataToFile(const std::vector<std::string>& container,const std::string& file_name) {
    std::ofstream save_to_file (file_name, std::ios::app);
    if (save_to_file.is_open()) {
        for (int i = 0; i < container.size(); i++) {
            save_to_file << encrypt(container[i]) << '\n';
        }
        save_to_file.close();
        std::cout << "Data successfully transferred to " << file_name << '\n';
    } else {
        std::cerr << "Unable to open file: " << file_name << '\n';
    }
}

void loadDataFromFile (std::vector<std::string>& container, std::string& file_name) {
    std::ifstream take_from_file (file_name);
    if (take_from_file.is_open()) {
        std::string line{};
        while (std::getline(take_from_file, line)) {
            container.push_back(decrypt(line));
            std::cout << "FROM FILE: " << decrypt(line) << std::endl;
        }
        take_from_file.close();
    } else {
        std::cerr << "Unable to open file: " << file_name << std::endl;
    }
}

int main() {

    std::cout << "Enter data:" << '\n';
    std::string text_file_name = "text_file.txt";
    std::string input{};
    std::vector<std::string> container;
    bool check = true;
    while (check) {
        while (std::cin >> input) {
            if (input == "end" || input == "End") {
                check = false;
                break;
            } else {
                container.push_back(input);
            }
        }
    }

    saveDataToFile(container, text_file_name);

    loadDataFromFile(container, text_file_name);

    return{};
}