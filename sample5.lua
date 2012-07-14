-- 테스트 함수
function test_error()
	
	print("test_error() called !!")
	
	test_error_1()
end

-- 테스트 함수
function test_error_1()

	print("test_error_1() called !!")
	
	test_error_2()
end

-- 테스트 함수
function test_error_2()

	print("test_error_2() called !!")
	
	-- 존재하지 않는 함수 호출을 시도한다.
	test_error_3()
end