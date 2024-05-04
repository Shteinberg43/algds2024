#include <gtest/gtest.h>
extern "C" {
#include "lab_2_treaps.h"
}
TEST(Treap_Insert_Test, Insert1)
{
	Treap t;
	t.root = NULL;
	Insert_note(&t, 10, 1);
	Insert_note(&t, 20, 2);
	Insert_note(&t, 30, 3);
	Insert_note(&t, 40, 4);
	Insert_note(&t, 50, 5);
	char str[100] = "\0";
	Treap_Print(t.root, str);
	EXPECT_STREQ("(10,1)(20,2)(30,3)(40,4)(50,5)", str);
}

TEST(Treap_Insert_Test, Insert2)
{
	Treap t;
	t.root = NULL;
	Insert_note(&t, 10, 10);
	Insert_note(&t, 20, 7);
	Insert_note(&t, 30, 25);
	Insert_note(&t, 40, 9);
	Insert_note(&t, 51, 2);
	char str[100] = "\0";
	Treap_Print(t.root, str);
	EXPECT_STREQ("(51,2)(20,7)(10,10)(40,9)(30,25)", str);
}

TEST(Treap_Delete_Test, Delete1)
{
	Treap t;
	t.root = NULL;
	Insert_note(&t, 10, 1);
	Insert_note(&t, 20, 2);
	Insert_note(&t, 30, 3);
	Insert_note(&t, 40, 4);
	Insert_note(&t, 50, 5);
	Delete_by_key(&t, 30);
	char str[100] = "\0";
	Treap_Print(t.root, str);
	EXPECT_STREQ("(10,1)(20,2)(40,4)(50,5)", str);
}

TEST(Treap_Delete_Test, Delete2)
{
	Treap t;
	t.root = NULL;
	Insert_note(&t, 10, 10);
	Insert_note(&t, 20, 7);
	Insert_note(&t, 30, 25);
	Insert_note(&t, 40, 9);
	Insert_note(&t, 51, 2);
	Delete_by_key(&t, 51);
	char str[100] = "\0";
	Treap_Print(t.root, str);
	EXPECT_STREQ("(20,7)(10,10)(40,9)(30,25)", str);
}

int main() {
	testing::InitGoogleTest();
	RUN_ALL_TESTS();
	//Treap t;
	//t.root = NULL;

	/*Insert_note(&t, 10, 10);
	Insert_note(&t, 20, 7);
	Insert_note(&t, 30, 25);
	Insert_note(&t, 40, 9);
	Insert_note(&t, 51, 2);
	Delete_by_key(&t, 51);
	char str[100] = "\0";
	Treap_Print(t.root, str);
	printf(str);*/
	return 0;
}