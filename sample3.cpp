// sample3.cpp : LuaTinker 의 클래스 기능을 알아본다.
//

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
};

#include "lua_tinker.h"

struct A
{
	A(int v) : value(v) {}
	int value;
};

struct base
{
	base() {}

	const char* is_base(){ return "this is base"; }
};

class test : public base
{
public:
	test(int val) : _test(val) {}
	~test() {}

	const char* is_test(){ return "this is test"; }

	void ret_void() {}
	int ret_int()				{ return _test;			}
	int ret_mul(int m) const	{ return _test * m;		}
	A get()						{ return A(_test);		}
	void set(A a)				{ _test = a.value;		}

	int _test;
};

test g_test(11);

int main()
{
	// Lua 를 초기화 한다.
	lua_State* L = lua_open();

	// Lua 기본 함수들을 로드한다.- print() 사용
	luaopen_base(L);
	// Lua 문자열 함수들을 로드한다.- string 사용
	luaopen_string(L);

	// base 클래스를 Lua 에 추가한다.
	lua_tinker::class_add<base>(L, "base");
	// base 의 함수를 등록한다.
	lua_tinker::class_def<base>(L, "is_base", &base::is_base);

	// test 클래스를 Lua 에 추가한다.
	lua_tinker::class_add<test>(L, "test");
	// test 가 base 에 상속 받았음을 알려준다.
	lua_tinker::class_inh<test, base>(L);
	// test 클래스 생성자를 등록한다.
	lua_tinker::class_con<test>(L, lua_tinker::constructor<test,int>);
	// test 의 함수들을 등록한다.
	lua_tinker::class_def<test>(L, "is_test", &test::is_test);
	lua_tinker::class_def<test>(L, "ret_void", &test::ret_void);
	lua_tinker::class_def<test>(L, "ret_int", &test::ret_int);
	lua_tinker::class_def<test>(L, "ret_mul", &test::ret_mul);
	lua_tinker::class_def<test>(L, "get", &test::get);
	lua_tinker::class_def<test>(L, "set", &test::set);
	lua_tinker::class_mem<test>(L, "_test", &test::_test);
	
	// Lua 전역 변수호 g_test 의 포인터를 등록한다.
	lua_tinker::set(L, "g_test", &g_test);

	// sample3.lua 파일을 로드/실행한다.
	lua_tinker::dofile(L, "sample3.lua");

	// 프로그램 종료
	lua_close(L);

	return 0;
}

