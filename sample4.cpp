// sample4.cpp : table 접근 법을 알아본다.
// table 은 빠른 접근을 위해서 stack 에 table을 복사해서 쓰게 된다. 
// Lua 에서 테이블은 스택 위에서는 포인터만 올라가고 실제 객체는 내부에서 관리된다.
// 따라서 잘못 사용할 경우 리턴을 깨먹거나 Lua 스택위의 지역 변수들에 문제를 일으킬 수도 있다.

extern "C" 
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
};

#include "lua_tinker.h"

int main()
{
	// Lua 를 초기화 한다.
	lua_State* L = lua_open();

	// Lua 기본 함수들을 로드한다.- print() 사용
	luaopen_base(L);

	// Lua 테이블을 생성하고 스택에 푸쉬한다.
	lua_tinker::table haha(L, "haha");

	// haha.value = 1 값을 넣는다.
	haha.set("value", 1);

	// table 내에 table을 만들어 넣는다.
	haha.set("inside", lua_tinker::table(L));

	// haha.inside 의 포인터를 스택위로 복사한다.
	lua_tinker::table inside = haha.get<lua_tinker::table>("inside");

	// inside.value = 2 값을 넣는다.
	inside.set("value", 2);

	// sample4.lua 파일을 로드/실행한다.
	lua_tinker::dofile(L, "sample4.lua");

	// Lua 에서 생성한 haha.test 값을 읽는다.
	const char* test = haha.get<const char*>("test");
	printf("haha.test = %s\n", test);

	// 전역에 등록하지 않고 Lua 스택에 빈 테이블을 생성한다.(지역변수)
	lua_tinker::table temp(L);

	// 빈 테이블.name 에 값을 넣는다.
	temp.set("name", "local table !!");

	// table을 의 인자로 사용하여 print_table 을 호출한다.
	lua_tinker::call<void>(L, "print_table", temp);

	// 함수가 리턴하는 table을 받는다.
	lua_tinker::table ret = lua_tinker::call<lua_tinker::table>(L, "return_table", "give me a table !!");
	printf("ret.name =\t%s\n", ret.get<const char*>("name"));

	// 프로그램 종료
	lua_close(L);

	return 0;
}

