-- 전역 haha 테이블을 확인한다.
print(haha)

-- 전역 haha.value를 출력한다.
print(haha.value)

-- 전역 haha.inside 테이블을 확인한다.
print(haha.inside)

-- 전역 haha.inside.value를 출력한다.
print(haha.inside.value)

-- haha.test 값을 넣는다.
haha.test = "input from lua"

-- LuaTinker 가 입력으로 테이블을 넘긴다.
function print_table(arg)
	print("arg = ", arg)
	print("arg.name = ", arg.name)
end

-- LuaTinker 에게 테이블을 넘긴다.
function return_table(arg)
	local ret = {}
	ret.name = arg
	return ret
end