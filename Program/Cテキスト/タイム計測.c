'�^�C���v��
'----------------------------------------------
'�o���u���쓮���Ă���I�[�g�X�C�b�`���m�܂ł̎��Ԃ��v�����܂��B

if �쓮���ԑ��� then
	'-----------------------------------------------
	'| �Z�Ѓ^���N  �b
	'-----------------------------------------------
	if SV12_���Đ؊��o���uA�� then
		if not(XSW9_���Đ؊�A��) then
			if LDP(CR2004) then
				inc(cntXSW9_���Đ؊�A��)
			end if
		else 
			if cntXSW9_���Đ؊�A��>0 and cntXSW9_���Đ؊�A��<>jdgXSW9_���Đ؊�A�� then
				passtimXSW9_���Đ؊�A��_val=cntXSW9_���Đ؊�A��*10
				jdgXSW9_���Đ؊�A��=cntXSW9_���Đ؊�A��
			end if				
		end if
	else
		cntXSW9_���Đ؊�A��=0
	end if
	if SV13_���Đ؊��o���uB�� then
		if not(XSW10_���Đ؊�B��) then
			if LDP(CR2004) then
				inc(cntXSW10_���Đ؊�B��)
			end if
		else 
			if cntXSW10_���Đ؊�B��>0 and cntXSW10_���Đ؊�B��<>jdgXSW10_���Đ؊�B�� then
				passtimXSW10_���Đ؊�B��_val=cntXSW10_���Đ؊�B��*10
				jdgXSW10_���Đ؊�B��=cntXSW10_���Đ؊�B��
			end if				
		end if
	else
		cntXSW10_���Đ؊�B��=0
	end if
	'-----------------------------------------------
	if SV2_�[�U�o���u�JA then
		if not(XSW1_�[�U�o���u�JA) then
			if LDP(CR2004) then
				inc(cntXSW1_�[�U�o���u�JA)
			end if
		else 
			if cntXSW1_�[�U�o���u�JA>0 and cntXSW1_�[�U�o���u�JA<>jdgXSW1_�[�U�o���u�JA then
				passtimXSW1_�[�U�o���u�JA_val=cntXSW1_�[�U�o���u�JA*10
				jdgXSW1_�[�U�o���u�JA=cntXSW1_�[�U�o���u�JA
			end if				
		end if
	else
		cntXSW1_�[�U�o���u�JA=0
	end if
	if not(SV2_�[�U�o���u�JA) then
		if not(XSW2_�[�U�o���u��A) then
			if LDP(CR2004) then
				inc(cntXSW2_�[�U�o���u��A)
			end if
		else 
			if cntXSW2_�[�U�o���u��A>0 and cntXSW2_�[�U�o���u��A<>jdgXSW2_�[�U�o���u��A then
				passtimXSW2_�[�U�o���u��A_val=cntXSW2_�[�U�o���u��A*10
				jdgXSW2_�[�U�o���u��A=cntXSW2_�[�U�o���u��A
			end if				
		end if
	else
		cntXSW2_�[�U�o���u��A=0
	end if
	'-----------------------------------------------
	if SV4_���؂�V���b�^�[�JA then
		if not(XSW3_���؂�V���b�^�[�JA) then
			if LDP(CR2004) then
				inc(cntXSW3_���؂�V���b�^�[�JA)
			end if
		else 
			if cntXSW3_���؂�V���b�^�[�JA>0 and cntXSW3_���؂�V���b�^�[�JA<>jdgXSW3_���؂�V���b�^�[�JA then
				passtimXSW3_���؂�V���b�^�[�JA_val=cntXSW3_���؂�V���b�^�[�JA*10
				jdgXSW3_���؂�V���b�^�[�JA=cntXSW3_���؂�V���b�^�[�JA
			end if				
		end if
	else
		cntXSW3_���؂�V���b�^�[�JA=0
	end if
	if SV5_���؂�V���b�^�[��A then
		if not(XSW4_���؂�V���b�^�[��A) then
			if LDP(CR2004) then
				inc(cntXSW4_���؂�V���b�^�[��A)
			end if				
		else 
			if cntXSW4_���؂�V���b�^�[��A>0 and cntXSW4_���؂�V���b�^�[��A<>jdgXSW4_���؂�V���b�^�[��A then
				passtimXSW4_���؂�V���b�^�[��A_val=cntXSW4_���؂�V���b�^�[��A*10
				jdgXSW4_���؂�V���b�^�[��A=cntXSW4_���؂�V���b�^�[��A
			end if				
		end if
	else
		cntXSW4_���؂�V���b�^�[��A=0
	end if
	'-----------------------------------------------
	if SV7_�[�U�o���u�JB then
		if not(XSW5_�[�U�o���u�JB) then
			if LDP(CR2004) then
				inc(cntXSW5_�[�U�o���u�JB)
			end if
		else 
			if cntXSW5_�[�U�o���u�JB>0 and cntXSW5_�[�U�o���u�JB<>jdgXSW5_�[�U�o���u�JB then
				passtimXSW5_�[�U�o���u�JB_val=cntXSW5_�[�U�o���u�JB*10
				jdgXSW5_�[�U�o���u�JB=cntXSW5_�[�U�o���u�JB
			end if				
		end if
	else
		cntXSW5_�[�U�o���u�JB=0
	end if
	if not(SV7_�[�U�o���u�JB) then
		if not(XSW6_�[�U�o���u��B) then
			if LDP(CR2004) then
				inc(cntXSW6_�[�U�o���u��B)
			end if
		else 
			if cntXSW6_�[�U�o���u��B>0 and cntXSW6_�[�U�o���u��B<>jdgXSW6_�[�U�o���u��B then
				passtimXSW6_�[�U�o���u��B_val=cntXSW6_�[�U�o���u��B*10
				jdgXSW6_�[�U�o���u��B=cntXSW6_�[�U�o���u��B
			end if				
		end if
	else
		cntXSW6_�[�U�o���u��B=0
	end if
	'-----------------------------------------------
	if SV9_���؂�V���b�^�[�JB then
		if not(XSW7_���؂�V���b�^�[�JB) then
			if LDP(CR2004) then
				inc(cntXSW7_���؂�V���b�^�[�JB)
			end if
		else 
			if cntXSW7_���؂�V���b�^�[�JB>0 and cntXSW7_���؂�V���b�^�[�JB<>jdgXSW7_���؂�V���b�^�[�JB then
				passtimXSW7_���؂�V���b�^�[�JB_val=cntXSW7_���؂�V���b�^�[�JB*10
				jdgXSW7_���؂�V���b�^�[�JB=cntXSW7_���؂�V���b�^�[�JB
			end if				
		end if
	else
		cntXSW7_���؂�V���b�^�[�JB=0
	end if
	if SV10_���؂�V���b�^�[��B then
		if not(XSW8_���؂�V���b�^�[��B) then
			if LDP(CR2004) then
				inc(cntXSW8_���؂�V���b�^�[��B)
			end if
		else 
			if cntXSW8_���؂�V���b�^�[��B>0 and cntXSW8_���؂�V���b�^�[��B<>jdgXSW8_���؂�V���b�^�[��B then
				passtimXSW8_���؂�V���b�^�[��B_val=cntXSW8_���؂�V���b�^�[��B*10
				jdgXSW8_���؂�V���b�^�[��B=cntXSW8_���؂�V���b�^�[��B
			end if				
		end if
	else
		cntXSW8_���؂�V���b�^�[��B=0
	end if
	'-----------------------------------------------
	'| �Ȃ炵���u  �b
	'-----------------------------------------------
	if SV27_�Ȃ炵�O�i then
		if not(XSW28_�Ȃ炵�O�i�[) then
			if LDP(CR2004) then
				inc(cntXSW28_�Ȃ炵�O�i�[)
			end if
		else 
			if cntXSW28_�Ȃ炵�O�i�[>0 and cntXSW28_�Ȃ炵�O�i�[<>jdgXSW28_�Ȃ炵�O�i�[ then
				passtimXSW28_�Ȃ炵�O�i�[_val=cntXSW28_�Ȃ炵�O�i�[*10
				jdgXSW28_�Ȃ炵�O�i�[=cntXSW28_�Ȃ炵�O�i�[
			end if				
		end if
	else
		cntXSW28_�Ȃ炵�O�i�[=0
	end if
	if SV28_�Ȃ炵��� then
		if not(XSW27_�Ȃ炵��ޒ[) then
			if LDP(CR2004) then
				inc(cntXSW27_�Ȃ炵��ޒ[)
			end if
		else 
			if cntXSW27_�Ȃ炵��ޒ[>0 and cntXSW27_�Ȃ炵��ޒ[<>jdgXSW27_�Ȃ炵��ޒ[ then
				passtimXSW27_�Ȃ炵��ޒ[_val=cntXSW27_�Ȃ炵��ޒ[*10
				jdgXSW27_�Ȃ炵��ޒ[=cntXSW27_�Ȃ炵��ޒ[
			end if				
		end if
	else
		cntXSW27_�Ȃ炵��ޒ[=0
	end if
	'-----------------------------------------------
	if SV23_�Ȃ炵�O�i then
		if not(XSW24_�Ȃ炵�O�i�[) then
			if LDP(CR2004) then
				inc(cntXSW24_�Ȃ炵�O�i�[)
			end if
		else 
			if cntXSW24_�Ȃ炵�O�i�[>0 and cntXSW24_�Ȃ炵�O�i�[<>jdgXSW24_�Ȃ炵�O�i�[ then
				passtimXSW24_�Ȃ炵�O�i�[_val=cntXSW24_�Ȃ炵�O�i�[*10
				jdgXSW24_�Ȃ炵�O�i�[=cntXSW24_�Ȃ炵�O�i�[
			end if				
		end if
	else
		cntXSW24_�Ȃ炵�O�i�[=0
	end if
	if SV24_�Ȃ炵��� then
		if not(XSW23_�Ȃ炵��ޒ[) then
			if LDP(CR2004) then
				inc(cntXSW23_�Ȃ炵��ޒ[)
			end if
		else 
			if cntXSW23_�Ȃ炵��ޒ[>0 and cntXSW23_�Ȃ炵��ޒ[<>jdgXSW23_�Ȃ炵��ޒ[ then
				passtimXSW23_�Ȃ炵��ޒ[_val=cntXSW23_�Ȃ炵��ޒ[*10
				jdgXSW23_�Ȃ炵��ޒ[=cntXSW23_�Ȃ炵��ޒ[
			end if				
		end if
	else
		cntXSW23_�Ȃ炵��ޒ[=0
	end if
	'-----------------------------------------------
	if SV25_�Ȃ炵���~ then
		if not(XSW26_�Ȃ炵���~�[) then
			if LDP(CR2004) then
				inc(cntXSW26_�Ȃ炵���~�[)
			end if
		else 
			if cntXSW26_�Ȃ炵���~�[>0 and cntXSW26_�Ȃ炵���~�[<>jdgXSW26_�Ȃ炵���~�[ then
				passtimXSW26_�Ȃ炵���~�[_val=cntXSW26_�Ȃ炵���~�[*10
				jdgXSW26_�Ȃ炵���~�[=cntXSW26_�Ȃ炵���~�[
			end if				
		end if
	else
		cntXSW26_�Ȃ炵���~�[=0
	end if
	if SV26_�Ȃ炵�㏸ then
		if not(XSW25_�Ȃ炵�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW25_�Ȃ炵�㏸�[)
			end if
		else 
			if cntXSW25_�Ȃ炵�㏸�[>0 and cntXSW25_�Ȃ炵�㏸�[<>jdgXSW25_�Ȃ炵�㏸�[ then
				passtimXSW25_�Ȃ炵�㏸�[_val=cntXSW25_�Ȃ炵�㏸�[*10
				jdgXSW25_�Ȃ炵�㏸�[=cntXSW25_�Ȃ炵�㏸�[
			end if				
		end if
	else
		cntXSW25_�Ȃ炵�㏸�[=0
	end if
	'-----------------------------------------------
	'| �t�^�킹���u  �b
	'-----------------------------------------------
'	if SV64_���ʒu then
'		if XSW25_�Ȃ炵�㏸�[ or XSW112_���ʒu����ޒ[ then
'			if LDP(CR2004) then
'				inc(cntXSW111_���ʒu�E��ޒ[)
'			end if
'		else 
'			if cntXSW111_���ʒu�E��ޒ[>0 and cntXSW111_���ʒu�E��ޒ[<>jdgXSW111_���ʒu�E��ޒ[ then
'				passtimXSW111_���ʒu�E��ޒ[_val=cntXSW111_���ʒu�E��ޒ[*10
'				passtimXSW112_���ʒu����ޒ[_val=cntXSW111_���ʒu�E��ޒ[*10
'				jdgXSW111_���ʒu�E��ޒ[=cntXSW111_���ʒu�E��ޒ[
'			end if				
'		end if
'	else
'		cntXSW111_���ʒu�E��ޒ[=0
'	end if

	passtimXSW111_���ʒu�E��ޒ[_val=500
	passtimXSW112_���ʒu����ޒ[_val=500

	'-----------------------------------------------
	if SV38_�N�����v then
		if not(XSW43_�N�����v) then
			if LDP(CR2004) then
				inc(cntXSW43_�N�����v)
			end if
		else 
			if cntXSW43_�N�����v>0 and cntXSW43_�N�����v<>jdgXSW43_�N�����v then
				passtimXSW43_�N�����v_val=cntXSW43_�N�����v*10
				jdgXSW43_�N�����v=cntXSW43_�N�����v
			end if				
		end if
	else
		cntXSW43_�N�����v=0
	end if
	if SV39_�A���N�����v then
		if not(XSW44_�A���N�����v) then
			if LDP(CR2004) then
				inc(cntXSW44_�A���N�����v)
			end if
		else 
			if cntXSW44_�A���N�����v>0 and cntXSW44_�A���N�����v<>jdgXSW44_�A���N�����v then
				passtimXSW44_�A���N�����v_val=cntXSW44_�A���N�����v*10
				jdgXSW44_�A���N�����v=cntXSW44_�A���N�����v
			end if				
		end if
	else
		cntXSW44_�A���N�����v=0
	end if
	'-----------------------------------------------
	if SV35_�V�����_���~A then
		if not(XSW40_�V�����_���~�[A) then
			if LDP(CR2004) then
				inc(cntXSW40_�V�����_���~�[A)
			end if
		else 
			if cntXSW40_�V�����_���~�[A>0 and cntXSW40_�V�����_���~�[A<>jdgXSW40_�V�����_���~�[A then
				passtimXSW40_�V�����_���~�[A_val=cntXSW40_�V�����_���~�[A*10
				jdgXSW40_�V�����_���~�[A=cntXSW40_�V�����_���~�[A
			end if				
		end if
	else
		cntXSW40_�V�����_���~�[A=0
	end if
	if SV36_�V�����_�㏸B then
		if not(XSW39_�V�����_�㏸�[A) then
			if LDP(CR2004) then
				inc(cntXSW39_�V�����_�㏸�[A)
			end if
		else 
			if cntXSW39_�V�����_�㏸�[A>0 and cntXSW39_�V�����_�㏸�[A<>jdgXSW39_�V�����_�㏸�[A then
				passtimXSW39_�V�����_�㏸�[A_val=cntXSW39_�V�����_�㏸�[A*10
				jdgXSW39_�V�����_�㏸�[A=cntXSW39_�V�����_�㏸�[A
			end if				
		end if
	else
		cntXSW39_�V�����_�㏸�[A=0
	end if
	'-----------------------------------------------
	if SV37_�V�����_���~B then
		if not(XSW42_�V�����_���~�[B) then
			if LDP(CR2004) then
				inc(cntXSW42_�V�����_���~�[B)
			end if
		else 
			if cntXSW42_�V�����_���~�[B>0 and cntXSW42_�V�����_���~�[B<>jdgXSW42_�V�����_���~�[B then
				passtimXSW42_�V�����_���~�[B_val=cntXSW42_�V�����_���~�[B*10
				jdgXSW42_�V�����_���~�[B=cntXSW42_�V�����_���~�[B
			end if				
		end if
	else
		cntXSW42_�V�����_���~�[B=0
	end if
	if SV36_�V�����_�㏸B then
		if not(XSW41_�V�����_�㏸�[B) then
			if LDP(CR2004) then
				inc(cntXSW41_�V�����_�㏸�[B)
			end if
		else 
			if cntXSW41_�V�����_�㏸�[B>0 and cntXSW41_�V�����_�㏸�[B<>jdgXSW41_�V�����_�㏸�[B then
				passtimXSW41_�V�����_�㏸�[B_val=cntXSW41_�V�����_�㏸�[B*10
				jdgXSW41_�V�����_�㏸�[B=cntXSW41_�V�����_�㏸�[B
			end if				
		end if
	else
		cntXSW41_�V�����_�㏸�[B=0
	end if
	'-----------------------------------------------
	' | �t�^��葕�u �b
	'-----------------------------------------------
	if SV50_�N�����v then
		if not(XSW60_�N�����v) then
			if LDP(CR2004) then
				inc(cntXSW60_�N�����v)
			end if
		else 
			if cntXSW60_�N�����v>0 and cntXSW60_�N�����v<>jdgXSW60_�N�����v then
				passtimXSW60_�N�����v_val=cntXSW60_�N�����v*10
				jdgXSW60_�N�����v=cntXSW60_�N�����v
			end if				
		end if
	else
		cntXSW60_�N�����v=0
	end if
	if SV49_�A���N�����v then
		if not(XSW59_�A���N�����v) then
			if LDP(CR2004) then
				inc(cntXSW59_�A���N�����v)
			end if
		else 
			if cntXSW59_�A���N�����v>0 and cntXSW59_�A���N�����v<>jdgXSW59_�A���N�����v then
				passtimXSW59_�A���N�����v_val=cntXSW59_�A���N�����v*10
				jdgXSW59_�A���N�����v=cntXSW59_�A���N�����v
			end if				
		end if
	else
		cntXSW59_�A���N�����v=0
	end if
	'-----------------------------------------------
	if SV46_�V�����_���~A then
		if not(XSW56_�V�����_���~�[A) then
			if LDP(CR2004) then
				inc(cntXSW56_�V�����_���~�[A)
			end if
		else 
			if cntXSW56_�V�����_���~�[A>0 and cntXSW56_�V�����_���~�[A<>jdgXSW56_�V�����_���~�[A then
				passtimXSW56_�V�����_���~�[A_val=cntXSW56_�V�����_���~�[A*10
				jdgXSW56_�V�����_���~�[A=cntXSW56_�V�����_���~�[A
			end if				
		end if
	else
		cntXSW56_�V�����_���~�[A=0
	end if
	if SV45_�V�����_�㏸A then
		if not(XSW55_�V�����_�㏸�[A) then
			if LDP(CR2004) then
				inc(cntXSW55_�V�����_�㏸�[A)
			end if
		else 
			if cntXSW55_�V�����_�㏸�[A>0 and cntXSW55_�V�����_�㏸�[A<>jdgXSW55_�V�����_�㏸�[A then
				passtimXSW55_�V�����_�㏸�[A_val=cntXSW55_�V�����_�㏸�[A*10
				jdgXSW55_�V�����_�㏸�[A=cntXSW55_�V�����_�㏸�[A
			end if				
		end if
	else
		cntXSW55_�V�����_�㏸�[A=0
	end if
	'-----------------------------------------------
	if SV48_�V�����_���~B then
		if not(XSW58_�V�����_���~�[B) then
			if LDP(CR2004) then
				inc(cntXSW58_�V�����_���~�[B)
			end if
		else 
			if cntXSW58_�V�����_���~�[B>0 and cntXSW58_�V�����_���~�[B<>jdgXSW58_�V�����_���~�[B then
				passtimXSW58_�V�����_���~�[B_val=cntXSW58_�V�����_���~�[B*10
				jdgXSW58_�V�����_���~�[B=cntXSW58_�V�����_���~�[B
			end if				
		end if
	else
		cntXSW58_�V�����_���~�[B=0
	end if
	if SV47_�V�����_�㏸B then
		if not(XSW57_�V�����_�㏸�[B) then
			if LDP(CR2004) then
				inc(cntXSW57_�V�����_�㏸�[B)
			end if
		else 
			if cntXSW57_�V�����_�㏸�[B>0 and cntXSW57_�V�����_�㏸�[B<>jdgXSW57_�V�����_�㏸�[B then
				passtimXSW57_�V�����_�㏸�[B_val=cntXSW57_�V�����_�㏸�[B*10
				jdgXSW57_�V�����_�㏸�[B=cntXSW57_�V�����_�㏸�[B
			end if				
		end if
	else
		cntXSW57_�V�����_�㏸�[B=0
	end if
	'-----------------------------------------------
	' | ���͂񌟒m �b
	'-----------------------------------------------
	if SV58_�V�����_ then
		if not(XSW80_�V�����_���~�[) then
			if LDP(CR2004) then
				inc(cntXSW80_�V�����_���~�[)
			end if
		else 
			if cntXSW80_�V�����_���~�[>0 and cntXSW80_�V�����_���~�[<>jdgXSW80_�V�����_���~�[ then
				passtimXSW80_�V�����_���~�[_val=cntXSW80_�V�����_���~�[*10
				jdgXSW80_�V�����_���~�[=cntXSW80_�V�����_���~�[
			end if				
		end if
	else
		cntXSW80_�V�����_���~�[=0
	end if
	if not(SV58_�V�����_) then
		if not(XSW73_�V�����_�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW73_�V�����_�㏸�[)
			end if
		else 
			if cntXSW73_�V�����_�㏸�[>0 and cntXSW73_�V�����_�㏸�[<>jdgXSW73_�V�����_�㏸�[ then
				passtimXSW73_�V�����_�㏸�[_val=cntXSW73_�V�����_�㏸�[*10
				jdgXSW73_�V�����_�㏸�[=cntXSW73_�V�����_�㏸�[
			end if				
		end if
	else
		cntXSW73_�V�����_�㏸�[=0
	end if
	'-----------------------------------------------
	' | �޷��ё��u �b
	'-----------------------------------------------
	if SV52_�V�����_ then
		if not(XSW62_�V�����_���~�[) then
			if LDP(CR2004) then
				inc(cntXSW62_�V�����_���~�[)
			end if
		else 
			if cntXSW62_�V�����_���~�[>0 and cntXSW62_�V�����_���~�[<>jdgXSW62_�V�����_���~�[ then
				passtimXSW62_�V�����_���~�[_val=cntXSW62_�V�����_���~�[*10
				jdgXSW62_�V�����_���~�[=cntXSW62_�V�����_���~�[
			end if				
		end if
	else
		cntXSW62_�V�����_���~�[=0
	end if
	if not(SV52_�V�����_) then
		if not(XSW61_�V�����_�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW61_�V�����_�㏸�[)
			end if
		else 
			if cntXSW61_�V�����_�㏸�[>0 and cntXSW61_�V�����_�㏸�[<>jdgXSW61_�V�����_�㏸�[ then
				passtimXSW61_�V�����_�㏸�[_val=cntXSW61_�V�����_�㏸�[*10
				jdgXSW61_�V�����_�㏸�[=cntXSW61_�V�����_�㏸�[
			end if				
		end if
	else
		cntXSW61_�V�����_�㏸�[=0
	end if

'-----------------------------------------------
' | �R���x�A �X�g�b�p�[�A�N�����v �b
'-----------------------------------------------

	'-----------------------------------------------
	' | ���t�^���~���uB �b
	'-----------------------------------------------
	if SV100_���t�g���~ then
		if not(XSW17_���t�g���~�[) then
			if LDP(CR2004) then
				inc(cntXSW17_���t�g���~�[)
			end if
		else 
			if cntXSW17_���t�g���~�[>0 and cntXSW17_���t�g���~�[<>jdgXSW17_���t�g���~�[ then
				passtimXSW17_���t�g���~�[_val=cntXSW17_���t�g���~�[*10
				jdgXSW17_���t�g���~�[=cntXSW17_���t�g���~�[
			end if				
		end if
	else
		cntXSW17_���t�g���~�[=0
	end if
	if SV20_���t�g�㏸ then
		if not(XSW18_���t�g�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW18_���t�g�㏸�[)
			end if
		else 
			if cntXSW18_���t�g�㏸�[>0 and cntXSW18_���t�g�㏸�[<>jdgXSW18_���t�g�㏸�[ then
				passtimXSW18_���t�g�㏸�[_val=cntXSW18_���t�g�㏸�[*10
				jdgXSW18_���t�g�㏸�[=cntXSW18_���t�g�㏸�[
			end if				
		end if
	else
		cntXSW18_���t�g�㏸�[=0
	end if
	'-----------------------------------------------
	' | �����R���x�AA �b
	'-----------------------------------------------
	if SV14_�X�g�b�p then
		if not(XSW12_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW12_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW12_�X�g�b�p�㏸�[>0 and cntXSW12_�X�g�b�p�㏸�[<>jdgXSW12_�X�g�b�p�㏸�[ then
				passtimXSW12_�X�g�b�p�㏸�[_val=cntXSW12_�X�g�b�p�㏸�[*10
				jdgXSW12_�X�g�b�p�㏸�[=cntXSW12_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW12_�X�g�b�p�㏸�[=0
	end if
	if not(SV14_�X�g�b�p) then
		if not(XSW11_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW11_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW11_�X�g�b�p���~�[>0 and cntXSW11_�X�g�b�p���~�[<>jdgXSW11_�X�g�b�p���~�[ then
				passtimXSW11_�X�g�b�p���~�[_val=cntXSW11_�X�g�b�p���~�[*10
				jdgXSW11_�X�g�b�p���~�[=cntXSW11_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW11_�X�g�b�p���~�[=0
	end if
	'-----------------------------------------------
	if SV15_�X�g�b�p then
		if not(XSW14_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW14_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW14_�X�g�b�p�㏸�[>0 and cntXSW14_�X�g�b�p�㏸�[<>jdgXSW14_�X�g�b�p�㏸�[ then
				passtimXSW14_�X�g�b�p�㏸�[_val=cntXSW14_�X�g�b�p�㏸�[*10
				jdgXSW14_�X�g�b�p�㏸�[=cntXSW14_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW14_�X�g�b�p�㏸�[=0
	end if
	if not(SV15_�X�g�b�p) then
		if not(XSW13_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW13_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW13_�X�g�b�p���~�[>0 and cntXSW13_�X�g�b�p���~�[<>jdgXSW13_�X�g�b�p���~�[ then
				passtimXSW13_�X�g�b�p���~�[_val=cntXSW13_�X�g�b�p���~�[*10
				jdgXSW13_�X�g�b�p���~�[=cntXSW13_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW13_�X�g�b�p���~�[=0
	end if
	'-----------------------------------------------
	' | �����R���x�AB �b
	'-----------------------------------------------
	if SV16_���t�g then
		if not(XSW16_���t�g�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW16_���t�g�㏸�[)
			end if
		else 
			if cntXSW16_���t�g�㏸�[>0 and cntXSW16_���t�g�㏸�[<>jdgXSW16_���t�g�㏸�[ then
				passtimXSW16_���t�g�㏸�[_val=cntXSW16_���t�g�㏸�[*10
				jdgXSW16_���t�g�㏸�[=cntXSW16_���t�g�㏸�[
			end if				
		end if
	else
		cntXSW16_���t�g�㏸�[=0
	end if
	if not(SV16_���t�g) then
		if not(XSW15_���t�g���~�[) then
			if LDP(CR2004) then
				inc(cntXSW15_���t�g���~�[)
			end if
		else 
			if cntXSW15_���t�g���~�[>0 and cntXSW15_���t�g���~�[<>jdgXSW15_���t�g���~�[ then
				passtimXSW15_���t�g���~�[_val=cntXSW15_���t�g���~�[*10
				jdgXSW15_���t�g���~�[=cntXSW15_���t�g���~�[
			end if				
		end if
	else
		cntXSW15_���t�g���~�[=0
	end if
	'-----------------------------------------------
	if SV21_�X�g�b�p then
		if not(XSW20_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW20_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW20_�X�g�b�p�㏸�[>0 and cntXSW20_�X�g�b�p�㏸�[<>jdgXSW20_�X�g�b�p�㏸�[ then
				passtimXSW20_�X�g�b�p�㏸�[_val=cntXSW20_�X�g�b�p�㏸�[*10
				jdgXSW20_�X�g�b�p�㏸�[=cntXSW20_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW20_�X�g�b�p�㏸�[=0
	end if
	if not(SV21_�X�g�b�p) then
		if not(XSW19_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW19_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW19_�X�g�b�p���~�[>0 and cntXSW19_�X�g�b�p���~�[<>jdgXSW19_�X�g�b�p���~�[ then
				passtimXSW19_�X�g�b�p���~�[_val=cntXSW19_�X�g�b�p���~�[*10
				jdgXSW19_�X�g�b�p���~�[=cntXSW19_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW19_�X�g�b�p���~�[=0
	end if
	'-----------------------------------------------
	if SV22_�X�g�b�p then
		if not(XSW22_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW22_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW22_�X�g�b�p�㏸�[>0 and cntXSW22_�X�g�b�p�㏸�[<>jdgXSW22_�X�g�b�p�㏸�[ then
				passtimXSW22_�X�g�b�p�㏸�[_val=cntXSW22_�X�g�b�p�㏸�[*10
				jdgXSW22_�X�g�b�p�㏸�[=cntXSW22_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW22_�X�g�b�p�㏸�[=0
	end if
	if not(SV22_�X�g�b�p) then
		if not(XSW21_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW21_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW21_�X�g�b�p���~�[>0 and cntXSW21_�X�g�b�p���~�[<>jdgXSW21_�X�g�b�p���~�[ then
				passtimXSW21_�X�g�b�p���~�[_val=cntXSW21_�X�g�b�p���~�[*10
				jdgXSW21_�X�g�b�p���~�[=cntXSW21_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW21_�X�g�b�p���~�[=0
	end if
	'-----------------------------------------------
	' | �����R���x�AC �b
	'-----------------------------------------------
	if SV33_���t�g then
		if not(XSW38_���t�g�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW38_���t�g�㏸�[)
			end if
		else 
			if cntXSW38_���t�g�㏸�[>0 and cntXSW38_���t�g�㏸�[<>jdgXSW38_���t�g�㏸�[ then
				passtimXSW38_���t�g�㏸�[_val=cntXSW38_���t�g�㏸�[*10
				jdgXSW38_���t�g�㏸�[=cntXSW38_���t�g�㏸�[
			end if				
		end if
	else
		cntXSW38_���t�g�㏸�[=0
	end if
	if not(SV33_���t�g) then
		if not(XSW37_���t�g���~�[) then
			if LDP(CR2004) then
				inc(cntXSW37_���t�g���~�[)
			end if
		else 
			if cntXSW37_���t�g���~�[>0 and cntXSW37_���t�g���~�[<>jdgXSW37_���t�g���~�[ then
				passtimXSW37_���t�g���~�[_val=cntXSW37_���t�g���~�[*10
				jdgXSW37_���t�g���~�[=cntXSW37_���t�g���~�[
			end if				
		end if
	else
		cntXSW37_���t�g���~�[=0
	end if
	'-----------------------------------------------
	if SV65_�X�g�b�p then
		if not(XSW75_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW75_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW75_�X�g�b�p�㏸�[>0 and cntXSW75_�X�g�b�p�㏸�[<>jdgXSW75_�X�g�b�p�㏸�[ then
				passtimXSW75_�X�g�b�p�㏸�[_val=cntXSW75_�X�g�b�p�㏸�[*10
				jdgXSW75_�X�g�b�p�㏸�[=cntXSW75_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW75_�X�g�b�p�㏸�[=0
	end if	
	if not(SV65_�X�g�b�p) then
		if not(XSW74_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW74_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW74_�X�g�b�p���~�[>0 and cntXSW74_�X�g�b�p���~�[<>jdgXSW74_�X�g�b�p���~�[ then
				passtimXSW74_�X�g�b�p���~�[_val=cntXSW74_�X�g�b�p���~�[*10
				jdgXSW74_�X�g�b�p���~�[=cntXSW74_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW74_�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if SV31_�N�����v then
		if not(XSW34_�N�����v�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW34_�N�����v�㏸�[)
			end if
		else 
			if cntXSW34_�N�����v�㏸�[>0 and cntXSW34_�N�����v�㏸�[<>jdgXSW34_�N�����v�㏸�[ then
				passtimXSW34_�N�����v�㏸�[_val=cntXSW34_�N�����v�㏸�[*10
				jdgXSW34_�N�����v�㏸�[=cntXSW34_�N�����v�㏸�[
			end if				
		end if
	else
		cntXSW34_�N�����v�㏸�[=0
	end if	
	if not(SV31_�N�����v) then
		if not(XSW33_�N�����v���~�[) then
			if LDP(CR2004) then
				inc(cntXSW33_�N�����v���~�[)
			end if
		else 
			if cntXSW33_�N�����v���~�[>0 and cntXSW33_�N�����v���~�[<>jdgXSW33_�N�����v���~�[ then
				passtimXSW33_�N�����v���~�[_val=cntXSW33_�N�����v���~�[*10
				jdgXSW33_�N�����v���~�[=cntXSW33_�N�����v���~�[
			end if				
		end if
	else
		cntXSW33_�N�����v���~�[=0
	end if	
	'-----------------------------------------------
	if SV29_�X�g�b�p then
		if not(XSW30_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW30_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW30_�X�g�b�p�㏸�[>0 and cntXSW30_�X�g�b�p�㏸�[<>jdgXSW30_�X�g�b�p�㏸�[ then
				passtimXSW30_�X�g�b�p�㏸�[_val=cntXSW30_�X�g�b�p�㏸�[*10
				jdgXSW30_�X�g�b�p�㏸�[=cntXSW30_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW30_�X�g�b�p�㏸�[=0
	end if	
	if not(SV29_�X�g�b�p) then
		if not(XSW29_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW29_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW29_�X�g�b�p���~�[>0 and cntXSW29_�X�g�b�p���~�[<>jdgXSW29_�X�g�b�p���~�[ then
				passtimXSW29_�X�g�b�p���~�[_val=cntXSW29_�X�g�b�p���~�[*10
				jdgXSW29_�X�g�b�p���~�[=cntXSW29_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW29_�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if SV32_�N�����v then
		if not(XSW36_�N�����v�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW36_�N�����v�㏸�[)
			end if
		else 
			if cntXSW36_�N�����v�㏸�[>0 and cntXSW36_�N�����v�㏸�[<>jdgXSW36_�N�����v�㏸�[ then
				passtimXSW36_�N�����v�㏸�[_val=cntXSW36_�N�����v�㏸�[*10
				jdgXSW36_�N�����v�㏸�[=cntXSW36_�N�����v�㏸�[
			end if				
		end if
	else
		cntXSW36_�N�����v�㏸�[=0
	end if	
	
	if not(SV32_�N�����v) then
		if not(XSW35_�N�����v���~�[) then
			if LDP(CR2004) then
				inc(cntXSW35_�N�����v���~�[)
			end if
		else 
			if cntXSW35_�N�����v���~�[>0 and cntXSW35_�N�����v���~�[<>jdgXSW35_�N�����v���~�[ then
				passtimXSW35_�N�����v���~�[_val=cntXSW35_�N�����v���~�[*10
				jdgXSW35_�N�����v���~�[=cntXSW35_�N�����v���~�[
			end if				
		end if
	else
		cntXSW35_�N�����v���~�[=0
	end if	
	'-----------------------------------------------
	if SV30_�X�g�b�p then
		if not(XSW32_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW32_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW32_�X�g�b�p�㏸�[>0 and cntXSW32_�X�g�b�p�㏸�[<>jdgXSW32_�X�g�b�p�㏸�[ then
				passtimXSW32_�X�g�b�p�㏸�[_val=cntXSW32_�X�g�b�p�㏸�[*10
				jdgXSW32_�X�g�b�p�㏸�[=cntXSW32_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW32_�X�g�b�p�㏸�[=0
	end if	
	
	if not(SV30_�X�g�b�p) then
		if not(XSW31_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW31_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW31_�X�g�b�p���~�[>0 and cntXSW31_�X�g�b�p���~�[<>jdgXSW31_�X�g�b�p���~�[ then
				passtimXSW31_�X�g�b�p���~�[_val=cntXSW31_�X�g�b�p���~�[*10
				jdgXSW31_�X�g�b�p���~�[=cntXSW31_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW31_�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	' | �����R���x�AD �b
	'-----------------------------------------------
	if SV41_���t�g then
		if not(XSW48_���t�g�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW48_���t�g�㏸�[)
			end if
		else 
			if cntXSW48_���t�g�㏸�[>0 and cntXSW48_���t�g�㏸�[<>jdgXSW48_���t�g�㏸�[ then
				passtimXSW48_���t�g�㏸�[_val=cntXSW48_���t�g�㏸�[*10
				jdgXSW48_���t�g�㏸�[=cntXSW48_���t�g�㏸�[
			end if				
		end if
	else
		cntXSW48_���t�g�㏸�[=0
	end if	
	
	if not(SV41_���t�g) then
		if not(XSW47_���t�g���~�[) then
			if LDP(CR2004) then
				inc(cntXSW47_���t�g���~�[)
			end if
		else 
			if cntXSW47_���t�g���~�[>0 and cntXSW47_���t�g���~�[<>jdgXSW47_���t�g���~�[ then
				passtimXSW47_���t�g���~�[_val=cntXSW47_���t�g���~�[*10
				jdgXSW47_���t�g���~�[=cntXSW47_���t�g���~�[
			end if				
		end if
	else
		cntXSW47_���t�g���~�[=0
	end if	
	'-----------------------------------------------
	if SV40_�X�g�b�p then
		if not(XSW46_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW46_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW46_�X�g�b�p�㏸�[>0 and cntXSW46_�X�g�b�p�㏸�[<>jdgXSW46_�X�g�b�p�㏸�[ then
				passtimXSW46_�X�g�b�p�㏸�[_val=cntXSW46_�X�g�b�p�㏸�[*10
				jdgXSW46_�X�g�b�p�㏸�[=cntXSW46_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW46_�X�g�b�p�㏸�[=0
	end if	
	
	if not(SV40_�X�g�b�p) then
		if not(XSW45_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW45_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW45_�X�g�b�p���~�[>0 and cntXSW45_�X�g�b�p���~�[<>jdgXSW45_�X�g�b�p���~�[ then
				passtimXSW45_�X�g�b�p���~�[_val=cntXSW45_�X�g�b�p���~�[*10
				jdgXSW45_�X�g�b�p���~�[=cntXSW45_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW45_�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if SV57_�o�L���[�����t�g then
		if not(XSW72_�o�L���[�}���t�g�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW72_�o�L���[�}���t�g�㏸�[)
			end if
		else 
			if cntXSW72_�o�L���[�}���t�g�㏸�[>0 and cntXSW72_�o�L���[�}���t�g�㏸�[<>jdgXSW72_�o�L���[�}���t�g�㏸�[ then
				passtimXSW72_�o�L���[�}���t�g�㏸�[_val=cntXSW72_�o�L���[�}���t�g�㏸�[*10
				jdgXSW72_�o�L���[�}���t�g�㏸�[=cntXSW72_�o�L���[�}���t�g�㏸�[
			end if				
		end if
	else
		cntXSW72_�o�L���[�}���t�g�㏸�[=0
	end if	
	
	if not(SV57_�o�L���[�����t�g) then
		if not(XSW71_�o�L���[�}���t�g���~�[) then
			if LDP(CR2004) then
				inc(cntXSW71_�o�L���[�}���t�g���~�[)
			end if
		else 
			if cntXSW71_�o�L���[�}���t�g���~�[>0 and cntXSW71_�o�L���[�}���t�g���~�[<>jdgXSW71_�o�L���[�}���t�g���~�[ then
				passtimXSW71_�o�L���[�}���t�g���~�[_val=cntXSW71_�o�L���[�}���t�g���~�[*10
				jdgXSW71_�o�L���[�}���t�g���~�[=cntXSW71_�o�L���[�}���t�g���~�[
			end if				
		end if
	else
		cntXSW71_�o�L���[�}���t�g���~�[=0
	end if	
	'-----------------------------------------------
	if SV42_�X�g�b�p then
		if not(XSW50_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW50_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW50_�X�g�b�p�㏸�[>0 and cntXSW50_�X�g�b�p�㏸�[<>jdgXSW50_�X�g�b�p�㏸�[ then
				passtimXSW50_�X�g�b�p�㏸�[_val=cntXSW50_�X�g�b�p�㏸�[*10
				jdgXSW50_�X�g�b�p�㏸�[=cntXSW50_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW50_�X�g�b�p�㏸�[=0
	end if	
	
	if not(SV42_�X�g�b�p) then
		if not(XSW49_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW49_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW49_�X�g�b�p���~�[>0 and cntXSW49_�X�g�b�p���~�[<>jdgXSW49_�X�g�b�p���~�[ then
				passtimXSW49_�X�g�b�p���~�[_val=cntXSW49_�X�g�b�p���~�[*10
				jdgXSW49_�X�g�b�p���~�[=cntXSW49_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW49_�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if SV43_�X�g�b�p then
		if not(XSW52_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW52_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW52_�X�g�b�p�㏸�[>0 and cntXSW52_�X�g�b�p�㏸�[<>jdgXSW52_�X�g�b�p�㏸�[ then
				passtimXSW52_�X�g�b�p�㏸�[_val=cntXSW52_�X�g�b�p�㏸�[*10
				jdgXSW52_�X�g�b�p�㏸�[=cntXSW52_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW52_�X�g�b�p�㏸�[=0
	end if	
	
	if not(SV43_�X�g�b�p) then
		if not(XSW51_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW51_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW51_�X�g�b�p���~�[>0 and cntXSW51_�X�g�b�p���~�[<>jdgXSW51_�X�g�b�p���~�[ then
				passtimXSW51_�X�g�b�p���~�[_val=cntXSW51_�X�g�b�p���~�[*10
				jdgXSW51_�X�g�b�p���~�[=cntXSW51_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW51_�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if SV44_���t�g then
		if not(XSW54_���t�g�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW54_���t�g�㏸�[)
			end if
		else 
			if cntXSW54_���t�g�㏸�[>0 and cntXSW54_���t�g�㏸�[<>jdgXSW54_���t�g�㏸�[ then
				passtimXSW54_���t�g�㏸�[_val=cntXSW54_���t�g�㏸�[*10
				jdgXSW54_���t�g�㏸�[=cntXSW54_���t�g�㏸�[
			end if				
		end if
	else
		cntXSW54_���t�g�㏸�[=0
	end if	
	
	if not(SV44_���t�g) then
		if not(XSW53_���t�g���~�[) then
			if LDP(CR2004) then
				inc(cntXSW53_���t�g���~�[)
			end if
		else 
			if cntXSW53_���t�g���~�[>0 and cntXSW53_���t�g���~�[<>jdgXSW53_���t�g���~�[ then
				passtimXSW53_���t�g���~�[_val=cntXSW53_���t�g���~�[*10
				jdgXSW53_���t�g���~�[=cntXSW53_���t�g���~�[
			end if				
		end if
	else
		cntXSW53_���t�g���~�[=0
	end if	
	'-----------------------------------------------
	' | �����R���x�AE �b
	'-----------------------------------------------
	if SV53_�X�g�b�p then
		if not(XSW64_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW64_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW64_�X�g�b�p�㏸�[>0 and cntXSW64_�X�g�b�p�㏸�[<>jdgXSW64_�X�g�b�p�㏸�[ then
				passtimXSW64_�X�g�b�p�㏸�[_val=cntXSW64_�X�g�b�p�㏸�[*10
				jdgXSW64_�X�g�b�p�㏸�[=cntXSW64_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW64_�X�g�b�p�㏸�[=0
	end if	
	
	if not(SV53_�X�g�b�p) then
		if not(XSW63_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW63_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW63_�X�g�b�p���~�[>0 and cntXSW63_�X�g�b�p���~�[<>jdgXSW63_�X�g�b�p���~�[ then
				passtimXSW63_�X�g�b�p���~�[_val=cntXSW63_�X�g�b�p���~�[*10
				jdgXSW63_�X�g�b�p���~�[=cntXSW63_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW63_�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if SV54_�X�g�b�p then
		if not(XSW66_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW66_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW66_�X�g�b�p�㏸�[>0 and cntXSW66_�X�g�b�p�㏸�[<>jdgXSW66_�X�g�b�p�㏸�[ then
				passtimXSW66_�X�g�b�p�㏸�[_val=cntXSW66_�X�g�b�p�㏸�[*10
				jdgXSW66_�X�g�b�p�㏸�[=cntXSW66_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW66_�X�g�b�p�㏸�[=0
	end if	
	
	if not(SV54_�X�g�b�p) then
		if not(XSW65_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW65_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW65_�X�g�b�p���~�[>0 and cntXSW65_�X�g�b�p���~�[<>jdgXSW65_�X�g�b�p���~�[ then
				passtimXSW65_�X�g�b�p���~�[_val=cntXSW65_�X�g�b�p���~�[*10
				jdgXSW65_�X�g�b�p���~�[=cntXSW65_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW65_�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	' | �����R���x�AF �b
	'-----------------------------------------------
	if SV56_�X�g�b�p then
		if not(XSW70_�X�g�b�p�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW70_�X�g�b�p�㏸�[)
			end if
		else 
			if cntXSW70_�X�g�b�p�㏸�[>0 and cntXSW70_�X�g�b�p�㏸�[<>jdgXSW70_�X�g�b�p�㏸�[ then
				passtimXSW70_�X�g�b�p�㏸�[_val=cntXSW70_�X�g�b�p�㏸�[*10
				jdgXSW70_�X�g�b�p�㏸�[=cntXSW70_�X�g�b�p�㏸�[
			end if				
		end if
	else
		cntXSW70_�X�g�b�p�㏸�[=0
	end if	
	
	if not(SV56_�X�g�b�p) then
		if not(XSW69_�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW69_�X�g�b�p���~�[)
			end if
		else 
			if cntXSW69_�X�g�b�p���~�[>0 and cntXSW69_�X�g�b�p���~�[<>jdgXSW69_�X�g�b�p���~�[ then
				passtimXSW69_�X�g�b�p���~�[_val=cntXSW69_�X�g�b�p���~�[*10
				jdgXSW69_�X�g�b�p���~�[=cntXSW69_�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW69_�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if SV55_���t�g then
		if not(XSW68_���t�g�㏸�[) then
			if LDP(CR2004) then
				inc(cntXSW68_���t�g�㏸�[)
			end if
		else 
			if cntXSW68_���t�g�㏸�[>0 and cntXSW68_���t�g�㏸�[<>jdgXSW68_���t�g�㏸�[ then
				passtimXSW68_���t�g�㏸�[_val=cntXSW68_���t�g�㏸�[*10
				jdgXSW68_���t�g�㏸�[=cntXSW68_���t�g�㏸�[
			end if				
		end if
	else
		cntXSW68_���t�g�㏸�[=0
	end if	
	
	if not(SV55_���t�g) then
		if not(XSW67_���t�g���~�[) then
			if LDP(CR2004) then
				inc(cntXSW67_���t�g���~�[)
			end if
		else 
			if cntXSW67_���t�g���~�[>0 and cntXSW67_���t�g���~�[<>jdgXSW67_���t�g���~�[ then
				passtimXSW67_���t�g���~�[_val=cntXSW67_���t�g���~�[*10
				jdgXSW67_���t�g���~�[=cntXSW67_���t�g���~�[
			end if				
		end if
	else
		cntXSW67_���t�g���~�[=0
	end if	
	'-----------------------------------------------
	' | ���R���x�A �b
	'-----------------------------------------------	
	if not(SV71_���t�^�X�g�b�p) then
		if not(XSW85_���t�^�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW85_���t�^�X�g�b�p���~�[)
			end if
		else 
			if cntXSW85_���t�^�X�g�b�p���~�[>0 and cntXSW85_���t�^�X�g�b�p���~�[<>jdgXSW85_���t�^�X�g�b�p���~�[ then
				passtimXSW85_���t�^�X�g�b�p���~�[_val=cntXSW85_���t�^�X�g�b�p���~�[*10
				jdgXSW85_���t�^�X�g�b�p���~�[=cntXSW85_���t�^�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW85_���t�^�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if not(SV77_���t�^�X�g�b�p) then
		if not(XSW90_���t�^�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW90_���t�^�X�g�b�p���~�[)
			end if
		else 
			if cntXSW90_���t�^�X�g�b�p���~�[>0 and cntXSW90_���t�^�X�g�b�p���~�[<>jdgXSW90_���t�^�X�g�b�p���~�[ then
				passtimXSW90_���t�^�X�g�b�p���~�[_val=cntXSW90_���t�^�X�g�b�p���~�[*10
				jdgXSW90_���t�^�X�g�b�p���~�[=cntXSW90_���t�^�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW90_���t�^�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if not(SV83_���t�^�X�g�b�p) then
		if not(XSW95_���t�^�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW95_���t�^�X�g�b�p���~�[)
			end if
		else 
			if cntXSW95_���t�^�X�g�b�p���~�[>0 and cntXSW95_���t�^�X�g�b�p���~�[<>jdgXSW95_���t�^�X�g�b�p���~�[ then
				passtimXSW95_���t�^�X�g�b�p���~�[_val=cntXSW95_���t�^�X�g�b�p���~�[*10
				jdgXSW95_���t�^�X�g�b�p���~�[=cntXSW95_���t�^�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW95_���t�^�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if not(SV89_���t�^�X�g�b�p) then
		if not(XSW100_���t�^�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW100_���t�^�X�g�b�p���~�[)
			end if
		else 
			if cntXSW100_���t�^�X�g�b�p���~�[>0 and cntXSW100_���t�^�X�g�b�p���~�[<>jdgXSW100_���t�^�X�g�b�p���~�[ then
				passtimXSW100_���t�^�X�g�b�p���~�[_val=cntXSW100_���t�^�X�g�b�p���~�[*10
				jdgXSW100_���t�^�X�g�b�p���~�[=cntXSW100_���t�^�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW100_���t�^�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
	if not(SV95_���t�^�X�g�b�p) then
		if not(XSW105_���t�^�X�g�b�p���~�[) then
			if LDP(CR2004) then
				inc(cntXSW105_���t�^�X�g�b�p���~�[)
			end if
		else 
			if cntXSW105_���t�^�X�g�b�p���~�[>0 and cntXSW105_���t�^�X�g�b�p���~�[<>jdgXSW105_���t�^�X�g�b�p���~�[ then
				passtimXSW105_���t�^�X�g�b�p���~�[_val=cntXSW105_���t�^�X�g�b�p���~�[*10
				jdgXSW105_���t�^�X�g�b�p���~�[=cntXSW105_���t�^�X�g�b�p���~�[
			end if				
		end if
	else
		cntXSW105_���t�^�X�g�b�p���~�[=0
	end if	
	'-----------------------------------------------
		


end if

