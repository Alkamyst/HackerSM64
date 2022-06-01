#ifndef COURSE_TABLE_H
#define COURSE_TABLE_H

// Start of the 3 cap courses in a row.
#define COURSE_CAP_COURSES COURSE_COTMC

#define DEFINE_COURSE(courseenum, _1) courseenum,
#define DEFINE_COURSES_END() \
    COURSE_BONUS_STAGES, \
    COURSE_STAGES_MAX = COURSE_BONUS_STAGES - 1, \
    COURSE_STAGES_COUNT = COURSE_STAGES_MAX,

#define DEFINE_BONUS_COURSE(courseenum, _1) courseenum,

enum CourseNum {
    #include "levels/course_defines.h"
    COURSE_MIN = COURSE_NONE + 1
};

#define COURSE_END 26
#define COURSE_MAX 25
#define COURSE_COUNT 25

#undef DEFINE_COURSE
#undef DEFINE_COURSES_END
#undef DEFINE_BONUS_COURSE

#define COURSE_IS_MAIN_COURSE(cmd) ((cmd) >= COURSE_MIN && (cmd) <= COURSE_STAGES_MAX)
#define COURSE_NUM_TO_INDEX(cmd) ((cmd) - 1)

#endif // COURSE_TABLE_H
