#include <gtest/gtest.h>

#include "DNA_Analyzer.h"

TEST(DNA_Analyzer, RabinKarpAlgorithm) {
  std::filesystem::path path_0{"tests/build/HIV-1_AF033819.3.txt"};
  std::filesystem::path path_1{"tests/build/test_1.txt"};
  std::filesystem::path path_2{"tests/build/output.txt"};

  ASSERT_TRUE(std::filesystem::exists(path_0));
  ASSERT_TRUE(std::filesystem::exists(path_1));

  std::ofstream fi("tests/build/output.txt");
  std::cout.rdbuf(fi.rdbuf());

  DNA_Analyzer analyzer;
  analyzer.RabinKarpAlgorithm(path_0, path_1);

  std::cout.rdbuf(std::cout.rdbuf());

  fi.close();

  std::ifstream fo("tests/build/output.txt");
  std::string content((std::istreambuf_iterator<char>(fo)),
                      (std::istreambuf_iterator<char>()));
  std::cout << " ";
  ASSERT_EQ(content, "65 9150 9182 \n");
}

TEST(DNA_Analyzer, NWAlgorithm) {
  std::filesystem::path path{"tests/build/test_2.txt"};
  ASSERT_TRUE(std::filesystem::exists(path));

  std::ofstream fi("tests/build/output.txt");
  std::cout.rdbuf(fi.rdbuf());

  DNA_Analyzer analyzer;
  analyzer.NWAlgorithm(path);

  std::cout.rdbuf(std::cout.rdbuf());

  fi.close();

  std::ifstream fo("tests/build/output.txt");
  std::string content((std::istreambuf_iterator<char>(fo)),
                      (std::istreambuf_iterator<char>()));
  std::cout << " ";
  ASSERT_EQ(content,
            "Max score: 10\nGGGCGACACTCCACCATAGA-\n |||||||| |||||||| | "
            "\n-GGCGACAC-CCACCATACAT\n");
}

TEST(DNA_Analyzer, RegexAlgorithm) {
  std::filesystem::path path{"tests/build/test_3.txt"};
  ASSERT_TRUE(std::filesystem::exists(path));

  std::ofstream fi("tests/build/output.txt");
  std::cout.rdbuf(fi.rdbuf());

  DNA_Analyzer analyzer;
  analyzer.RegexAlgorithm(path);

  std::cout.rdbuf(std::cout.rdbuf());

  fi.close();

  std::ifstream fo("tests/build/output.txt");
  std::string content((std::istreambuf_iterator<char>(fo)),
                      (std::istreambuf_iterator<char>()));
  std::cout << " ";
  ASSERT_EQ(content, "True\n");
}

TEST(DNA_Analyzer, KSimilarAlgorithm) {
  std::filesystem::path path{"tests/build/test_4.txt"};
  ASSERT_TRUE(std::filesystem::exists(path));

  std::ofstream fi("tests/build/output.txt");
  std::cout.rdbuf(fi.rdbuf());

  DNA_Analyzer analyzer;
  analyzer.KSimilarAlgorithm(path);

  std::cout.rdbuf(std::cout.rdbuf());

  fi.close();

  std::ifstream fo("tests/build/output.txt");
  std::string content((std::istreambuf_iterator<char>(fo)),
                      (std::istreambuf_iterator<char>()));
  std::cout << " ";
  ASSERT_EQ(content, "3\n");
}

TEST(DNA_Analyzer, WindowAlgorithm) {
  std::filesystem::path path{"tests/build/test_5.txt"};
  ASSERT_TRUE(std::filesystem::exists(path));

  std::ofstream fi("tests/build/output.txt");
  std::cout.rdbuf(fi.rdbuf());

  DNA_Analyzer analyzer;
  analyzer.WindowAlgorithm(path);

  std::cout.rdbuf(std::cout.rdbuf());

  fi.close();

  std::ifstream fo("tests/build/output.txt");
  std::string content((std::istreambuf_iterator<char>(fo)),
                      (std::istreambuf_iterator<char>()));
  std::cout << " ";
  ASSERT_EQ(content, "GACACCCACCATACAT\n");
}