-- lua coroutine 테스트 함수
function ThreadTest()
	print("ThreadTest 시작")
	
	print("TestFunc 호출")
	-- 내부에서 lua_yield() 가 호출된다.
	TestFunc()
	TestFunc2(1.2)
	print("TestFunc 종료")
	
	print("g_test::TestFunc() 호출")
	-- 내부에서 lua_yield() 가 호출된다.
	g_test:TestFunc()
	g_test:TestFunc2(2.3)
	print("g_test::TestFunc() 종료")
	
	print("ThreadTest 종료")
end
