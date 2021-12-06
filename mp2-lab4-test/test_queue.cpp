#include "pch.h"
#include <iostream>
#include "..\mp2-lab4-queue\TQueue.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> tq(5));
}

TEST(TQueue, cant_create_queue_with_negative_or_zero_size)
{
	ASSERT_ANY_THROW(TQueue<int> tq(-5));
	ASSERT_ANY_THROW(TQueue<int> tq(0));
}

TEST(TQueue, new_created_queue_is_empty)
{
	TQueue<int> tq(5);
	ASSERT_TRUE(tq.IsEmpty());
}

TEST(TQueue, new_created_queue_is_not_full)
{
	TQueue<int> q(5);
	ASSERT_FALSE(q.IsFull());
}

TEST(TQueue, full_queue_is_not_empty)
{
	TQueue<int> tq(10);
	for (int i = 0; i < 10; i++) {
		tq.Push(i);
	}

	ASSERT_FALSE(tq.IsEmpty());
}

TEST(TQueue, full_queue_is_full)
{
	TQueue<int> tq(10);
	for (int i = 0; i < 10; i++) {
		tq.Push(i);
	}
	
	ASSERT_TRUE(tq.IsFull());
}

TEST(TQueue, not_empty_queue_is_not_empty)
{
	TQueue<int> tq(2);
	tq.Push(0);

	ASSERT_FALSE(tq.IsEmpty());
}

TEST(TQueue, not_full_queue_is_not_full)
{
	TQueue<int> tq(2);
	tq.Push(0);

	ASSERT_FALSE(tq.IsFull());
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> tq(5);
	ASSERT_NO_THROW(TQueue<int> copy(tq));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	TQueue<int> tq(5);
	for (int i = 0; i < 5; i++)
		tq.Push(i);

	TQueue<int> copy(tq);

	EXPECT_EQ(copy, tq);
}

TEST(TQueue, copied_queue_has_its_own_memory)
{
	TQueue<int> tq(5);
	for (int i = 0; i < 5; i++)
		tq.Push(i);

	TQueue<int> copy(tq);
	copy.Clear();
	for (int i = 0; i < 5; i++)
		copy.Push(i + 1);

	for (int i = 0; i < 5; i++)
		EXPECT_NE(copy.Pop(), tq.Pop());
}

TEST(TQueue, can_assign_queues_of_equal_sizes)
{
	TQueue<int> tq1(5);
	for (int i = 0; i < 5; i++)
		tq1.Push(i);

	TQueue<int> tq2(5);
	tq2 = tq1;

	EXPECT_EQ(tq2, tq1);
}

TEST(TQueue, can_assign_queues_of_different_sizes)
{
	TQueue<int> tq1(5);
	for (int i = 0; i < 5; i++)
		tq1.Push(i);

	TQueue<int> tq2(7);
	tq2 = tq1;

	EXPECT_EQ(tq2, tq1);
}

TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue<int> tq(5);
	for (int i = 0; i < 5; i++)
		tq.Push(i);

	tq = tq;

	EXPECT_EQ(tq, tq);
}

TEST(TQueue, equal_queues_comparison_returns_true)
{
	TQueue<int> tq1(5);
	for (int i = 0; i < 5; i++)
		tq1.Push(i);

	TQueue<int> tq2(5);
	for (int i = 0; i < 5; i++)
		tq2.Push(i);

	EXPECT_EQ(tq1, tq2);
}

TEST(TQueue, unequal_queues_comparison_returns_false)
{
	TQueue<int> tq1(5);
	for (int i = 0; i < 5; i++)
		tq1.Push(i);

	TQueue<int> tq2(5);
	for (int i = 0; i < 5; i++)
		tq2.Push(2 * i);

	EXPECT_NE(tq1, tq2);
}

TEST(TQueue, queues_with_different_maxsizes_are_not_equal)
{
	TQueue<int> tq1(10);
	TQueue<int> tq2(20);

	EXPECT_NE(tq1, tq2);
}

TEST(TQueue, can_push_and_pop_single)
{
	TQueue<double> tq(5);
	double num = 25.12;
	double popped;

	ASSERT_NO_THROW(tq.Push(num));
	ASSERT_NO_THROW(popped = tq.Pop());
	EXPECT_EQ(popped, num);
}

TEST(TQueue, cant_push_to_a_full_queue)
{
	TQueue<int> tq(5);
	for (int i = 0; i < 5; i++)
		tq.Push(i);

	ASSERT_ANY_THROW(tq.Push(0));
}

TEST(TQueue, cant_pop_from_an_empty_queue)
{
	TQueue<int> tq(5);
	ASSERT_ANY_THROW(tq.Pop());
}

TEST(TQueue, can_clear_queue)
{
	TQueue<int> tq;
	for (int i = 0; i < 9; i++)
		tq.Push(i);

	ASSERT_NO_THROW(tq.Clear());
}

TEST(TQueue, cleared_queue_is_empty)
{
	TQueue<int> tq;
	for (int i = 0; i < 9; i++)
		tq.Push(i);

	tq.Clear();
	ASSERT_TRUE(tq.IsEmpty());
}

TEST(TQueue, cleared_queue_is_not_full)
{
	TQueue<int> tq;
	for (int i = 0; i < 9; i++)
		tq.Push(i);

	tq.Clear();
	ASSERT_FALSE(tq.IsFull());
}