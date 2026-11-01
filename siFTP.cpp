#include <iostream>
#include <string>
#include <fstream>
#include <curl/curl.h>
#include <yy981/andor.h>
#include <yy981/return.h>


size_t writeCallback(void* ptr, size_t size, size_t nmemb, void* stream) {
    std::ofstream* outFile = static_cast<std::ofstream*>(stream);
    outFile->write(static_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}

bool upload(const std::string filename, const std::string url, const std::string usernameAndPassword = "null") {
    CURL* curl;
    CURLcode res;
    FILE* file;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        file = fopen(filename.c_str(), "rb");
        if (!file) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, file);

        // 必要に応じてユーザー名とパスワードを設定
        if (usernameAndPassword != "null") {
            curl_easy_setopt(curl, CURLOPT_USERPWD, usernameAndPassword.c_str());
        }

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            fclose(file);
            curl_easy_cleanup(curl);
            return false;
        }

        fclose(file);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return true;
}

bool download(const std::string url, const std::string outfilename, const std::string usernameAndPassword = "null") {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        std::ofstream outFile(outfilename, std::ios::binary);
        if (!outFile) {
            std::cerr << "Failed to open file: " << outfilename << std::endl;
            return false;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outFile);

        // 必要に応じてユーザー名とパスワードを設定
        if (usernameAndPassword != "null") {
            curl_easy_setopt(curl, CURLOPT_USERPWD, usernameAndPassword.c_str());
        }

        // パッシブモードの設定 (FTP)
        curl_easy_setopt(curl, CURLOPT_FTP_USE_EPSV, 1L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        outFile.close();
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return true;
}



int main(int argc, char *argv[]) {
	if (argc != 5) return_u("SimpleFTP Upload <LocalPath> <URL> <username:passeord> \nSimpleFTP Download <URL> <LocalPath> <username:passeord>");
	if (is_or(argv[1],"upload","Upload","u","U")) upload(argv[2],argv[3],argv[4]);
	else if (is_or(argv[1],"download","Download","d","D")) download(argv[2],argv[3],argv[4]);
	else std::cerr << "Upload(upload,u,U) か Download(download,d,D) にしてください";
}