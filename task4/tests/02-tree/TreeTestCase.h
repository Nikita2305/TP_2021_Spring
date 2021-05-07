//
// Created by akhtyamovpavel on 5/1/20.
//

#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include <Tree.h>
#include <string>
#include <cstdio>
#include <stdlib.h>

class TreeTestCase : public ::testing::Test {
public:
    void setupTestSuite() {
        boost::filesystem::path dir = boost::filesystem::temp_directory_path() / boost::filesystem::unique_path("%%%%/%%%%");
        dir_level_2 = dir;
        dir_level_1 = dir_level_2.parent_path();
        boost::filesystem::create_directory(dir_level_1);
        boost::filesystem::create_directory(dir_level_2);
        std::string filepath = std::tmpnam(nullptr);
        std::ofstream f(filepath);
        f.close();
        std::string query = "mv " + filepath + " " + dir.native();
        system(query.c_str());
        boost::filesystem::remove(filepath);
        dir_level_3 = dir / boost::filesystem::path(filepath).filename();
    }
    void test1() {
        EXPECT_EQ(GetTree(dir_level_1.native(), false), getTrueTreeWithDirectories());
        EXPECT_EQ(GetTree(dir_level_1.native(), true), getTrueTreeWithoutDirectories());
    }
    void test2() {
        EXPECT_THROW(GetTree((dir_level_1 / boost::filesystem::unique_path("%%%%")).native(), false), std::invalid_argument);
        EXPECT_THROW(GetTree(dir_level_3.native(), false), std::invalid_argument);
    }
    void setupTest3() {
        boost::filesystem::create_directory(dir_level_1 / boost::filesystem::unique_path("%%%%"));
    }
    void test3() { 
        FilterEmptyNodes(GetTree(dir_level_1.native(), false), dir_level_1.native());
    } 
    void teardownTestSuite() { 
        boost::filesystem::remove_all(dir_level_1);
    }
private:
    boost::filesystem::path dir_level_1;
    boost::filesystem::path dir_level_2;
    boost::filesystem::path dir_level_3;
    FileNode getTrueTreeWithDirectories() {
        return FileNode{dir_level_1.filename().native(), true, {FileNode{dir_level_2.filename().native(), true, 
                                            {FileNode{dir_level_3.filename().native(), false, {}}}}}};
    }
    FileNode getTrueTreeWithoutDirectories() {
        return FileNode{dir_level_1.filename().native(), true, {FileNode{dir_level_2.filename().native(), true, {}}}};
    }
};
