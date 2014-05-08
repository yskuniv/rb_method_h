#include <stdio.h>
#include "rb_method.h"

int main(void)
{
	puts("RB_RANGE_EACH");
	/* (3..6).each do |n| puts "n = #{n}" end */
	RB_RANGE_EACH(3, 6, n,
		      ({
			      printf("n = %d\n", n);
		      }));

	puts("\nRB_TIMES");
	/* 5.times do |n| puts "n = #{n}" end */
	RB_TIMES(5, n,
		 ({
			 printf("n = %d\n", n);
		 }));

	const int a1[] = { 3, 4, 1, 2 };

	puts("\nRB_EACH");
	/* a1.each do |e| puts "e = #{e}" end */
	RB_EACH(a1, 4, e,
		({
			printf("e = %d\n", *e);
		}));

	puts("\nRB_EACH_ROTATE");
	/* a1.rotate(2).each do |e| puts "e = #{e}" end */
	RB_EACH_ROTATE(a1, 4, 2, e,
		       ({
			       printf("e = %d\n", *e);
		       }));

	puts("\nRB_INJECT");
	/* puts a1.inject(0) { |s, e| s + e } */
	printf("s = %d\n", RB_INJECT(a1, 4, 0, s, e, s + *e));

	struct {
		int id;
		int x;
	} a2[] = { { .id = 1, .x = 7 },
		   { .id = 2, .x = 3 },
		   { .id = 3, .x = 9 },
		   { .id = 4, .x = 2 } };

	puts("\nRB_MAX_BY");
	/* puts "id = #{a2.max_by { |e| e.x }.id}" */
	printf("id = %d\n", RB_MAX_BY(a2, 4, e, e->x)->id);

	puts("\nRB_MIN_BY");
	/* puts "id = #{a2.min_by { |e| e.x }.id}" */
	printf("id = %d\n", RB_MIN_BY(a2, 4, e, e->x)->id);

	puts("\nRB_FIND");
	/* puts "id = #{a2.find { |e| e.x < 5 }.id}" */
	printf("id = %d\n", RB_FIND(a2, 4, e, e->x < 5)->id);

	puts("\nRB_FIND_ROTATE");
	/* puts "id = #{a2.rotate(2).find { |e| e.x < 5 }.id}" */
	printf("id = %d\n", RB_FIND_ROTATE(a2, 4, 2, e, e->x < 5)->id);

	return 0;
}
