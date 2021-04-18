//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include <Tree.h>

class TreeTestCase : public ::testing::Test {
 public:
  void createDirectory() {
    boost::filesystem::create_directory("/tmp/1");
    boost::filesystem::create_directory("/tmp/1/1");
    std::ofstream f("/tmp/1/1/1.txt");
    f.close();
  }
  FileNode getTrueTreeWithDirectories() {
    return FileNode{"1", true, {FileNode{"1", true, {FileNode{"1.txt", false, {}}}}}};
  }
  FileNode getTrueTreeWithoutDirectories() {
    return FileNode{"1", true, {FileNode{"1", true, {}}}};
  }
  void deleteDirectory() {
    boost::filesystem::remove_all("/tmp/1");
  }
};

TEST_F(TreeTestCase, name) {
  createDirectory();

  EXPECT_EQ(GetTree("/tmp/1", false), getTrueTreeWithDirectories());
  EXPECT_EQ(GetTree("/tmp/1", true), getTrueTreeWithoutDirectories());
  FilterEmptyNodes(GetTree("/tmp/1", false), "/tmp/1");

  EXPECT_THROW(GetTree("/tmp/1/2", false), std::invalid_argument);
  EXPECT_THROW(GetTree("/tmp/1/1/1.txt", false), std::invalid_argument);

  deleteDirectory();
}
