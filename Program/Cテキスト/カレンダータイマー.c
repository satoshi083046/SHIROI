'�J�����_�[�^�C�}�[
'===================================================================================================================
'
'  �J�����_�[�^�C�}�[
'
'===================================================================================================================
if CR2008 then
	if 0 then
		�C�������E�N=16
		�C�������E��=10
		�C�������E��=13
		�C�������E��=15
		�C�������E��=30
		�C�������E�b=00
		�C�������E�j��=4
	end if
end if


if 0 then

	�o�ߎ��ԁE�N=0
	�o�ߎ��ԁE��=0
	�o�ߎ��ԁE��=0
	�o�ߎ��ԁE��=0
	�o�ߎ��ԁE��=0
	�o�ߎ��ԁE�b=0
	�c���ԁE�N=0
	�c���ԁE��=0
	�c���ԁE��=0
	�c���ԁE��=0
	�c���ԁE��=0
	�c���ԁE�b=0
	�\��ݒ莞���E��=0
	�\��ݒ莞���E��=0

end if
'------------------------------------------------------------------------------------------------------------
'�d��ON wait

tmr(wait_tim,#10)

if wait_tim.B then
'------------------------------------------------------------------------------------------------------------
'���ݎ����̎擾
get�N=CM700
get��=CM701
get��=CM702
get��=CM703
get��=CM704
get�b=CM705
get�j��=CM706

select case get�j�� 'http://www.asahi-net.or.jp/~ax2s-kmtn/ref/jisx0208.html
case 0
	get�j���R�[�h=$93FA 'http://kanji.free.fr/kanji.php?sjis=93FA
case 1
	get�j���R�[�h=$8C8E 'http://kanji.free.fr/kanji.php?sjis=8C8E
case 2
	get�j���R�[�h=$89CE 'http://kanji.free.fr/kanji.php?sjis=89CE
case 3
	get�j���R�[�h=$9085 'http://kanji.free.fr/kanji.php?sjis=9085
case 4
	get�j���R�[�h=$96D8 'http://kanji.free.fr/kanji.php?sjis=96D8
case 5
	get�j���R�[�h=$8BE0 'http://kanji.free.fr/kanji.php?sjis=8BE0
case 6
	get�j���R�[�h=$9379 'http://kanji.free.fr/kanji.php?sjis=9379
end select

'------------------------------------------------------------------------------------------------------------
'�I���X�C�b�`�Ɛݒ�

if 0<=�\��ݒ莞���E�� and 23>=�\��ݒ莞���E�� and 0<=�\��ݒ莞���E�� and 59>=�\��ݒ莞���E�� then

	�\��E��=�\��ݒ莞���E��
	�\��E��=�\��ݒ莞���E��
	set��.U=�\��E��.U		
	set��.U=�\��E��.U
	set�b=0

	select case get�j��
	case 0
		if �\��ݒ�E�� then
			�\��ݒ�flg=ON
	 		set�N=CM700
			set��=CM701
			set��=CM702
		else
			�\��ݒ�flg=OFF
		end if
	case 1
		if �\��ݒ�E�� then
			�\��ݒ�flg=ON		
	 		set�N=CM700
			set��=CM701
			set��=CM702
		else
			�\��ݒ�flg=OFF
		end if
	case 2
		if �\��ݒ�E�� then
			�\��ݒ�flg=ON
	 		set�N=CM700
			set��=CM701
			set��=CM702
		else
			�\��ݒ�flg=OFF
		end if
	case 3
		if �\��ݒ�E�� then
			�\��ݒ�flg=ON
			set�N=CM700
			set��=CM701
			set��=CM702
		else
			�\��ݒ�flg=OFF
		end if
	case 4
		if �\��ݒ�E�� then
			�\��ݒ�flg=ON
	 		set�N=CM700
			set��=CM701
			set��=CM702
		else
			�\��ݒ�flg=OFF	
		end if
	case 5
		if �\��ݒ�E�� then
			�\��ݒ�flg=ON
	 		set�N=CM700
			set��=CM701
			set��=CM702
		else
			�\��ݒ�flg=OFF	
		end if
	case 6
		if �\��ݒ�E�y then
			�\��ݒ�flg=ON	
	 		set�N=CM700
			set��=CM701
			set��=CM702
		else
			�\��ݒ�flg=OFF
		end if
	end select
else
	�\��ݒ莞���E��=�\��E��
	�\��ݒ莞���E��=�\��E��


end if
'------------------------------------------------------------------------------------------------------------
'�ݒ莞���ƌ��ݎ����̉��Z
'------------------------------------------------------------------------------------------------------------
if	�\��ݒ�flg=ON then

	if	0<=(sec(get�N) -sec(set�N)) then
		
		ONTIME=sec(set�N)<=sec(get�N) and (sec(set�N)+59) >sec(get�N) 'ON���: ���ݎ���~59�b��
		
		pasttime.D=sec(get�N) -sec(set�N) '�ݒ肩��̌o�ߎ���
		rsec(pasttime.D,�o�ߎ��ԁE�N)
		if 1<=�o�ߎ��ԁE�� then
			dec(�o�ߎ��ԁE��)
		end if
		if 1<=�o�ߎ��ԁE�� then
			dec(�o�ߎ��ԁE��)
		end if
		
		�c���ԁE�N=0
		�c���ԁE��=0
		�c���ԁE��=0
		�c���ԁE��=0
		�c���ԁE��=0
		�c���ԁE�b=0
	else
		ONTIME=OFF
		pasttime.D=sec(set�N) -sec(get�N) '�ݒ�܂ł̎c����
		rsec(pasttime.D,�c���ԁE�N)
		if 1<=�c���ԁE�� then
			dec(�c���ԁE��)
		end if
		if 1<=�c���ԁE�� then
			dec(�c���ԁE��)
		end if

		�o�ߎ��ԁE�N=0
		�o�ߎ��ԁE��=0
		�o�ߎ��ԁE��=0
		�o�ߎ��ԁE��=0
		�o�ߎ��ԁE��=0
		�o�ߎ��ԁE�b=0
	end if
else
		�c���ԁE�N=0
		�c���ԁE��=0
		�c���ԁE��=0
		�c���ԁE��=0
		�c���ԁE��=0
		�c���ԁE�b=0
		�o�ߎ��ԁE�N=0
		�o�ߎ��ԁE��=0
		�o�ߎ��ԁE��=0
		�o�ߎ��ԁE��=0
		�o�ߎ��ԁE��=0
		�o�ߎ��ԁE�b=0

		ONTIME=OFF
end if
'------------------------------------------------------------------------------------------------------------
'�z�Čo�ߎ��Ԃ̌v��
if ldp(�^�]��������) then
	�z��pasttime=0
	
	�z�Čo�ߎ��ԁE�N=0
	�z�Čo�ߎ��ԁE��=0
	�z�Čo�ߎ��ԁE��=0
	�z�Čo�ߎ��ԁE��=0
	�z�Čo�ߎ��ԁE��=0
	�z�Čo�ߎ��ԁE�b=0	

	set�z�āE�N=get�N	
	set�z�āE��=get��	
	set�z�āE��=get��
	set�z�āE��=get��
	set�z�āE��=get��
	set�z�āE�b=get�b	

end if

if �^�]�������� then
	�z��pasttime.D=sec(get�N)-sec(set�z�āE�N) '�ݒ肩��̌o�ߎ���
	rsec(�z��pasttime.D,�z�Čo�ߎ��ԁE�N)
else
	�z�Čo�ߎ��ԁE�N=0
	�z�Čo�ߎ��ԁE��=0
	�z�Čo�ߎ��ԁE��=0
	�z�Čo�ߎ��ԁE��=0
	�z�Čo�ߎ��ԁE��=0
	�z�Čo�ߎ��ԁE�b=0
	

end if
'------------------------------------------------------------------------------------------------------------
'�Z�Ў��Ԍv���^���NA

'set�Z�Ў���A�E�N

'�Z�Ў��ԃ^���NA�E�N
'�Z�Ў��ԃ^���NA�E��
'�Z�Ў��ԃ^���NA�E��
'�Z�Ў��ԃ^���NA�E��
'�Z�Ў��ԃ^���NA�E��
'�Z�Ў��ԃ^���NA�E�b
'�Z�Ў��ԃ^���NA�E�j��

tmr(pnlPB�����ėLA or PDL2_�p�h���Z���T�[����A or FLOS3_LMT121,tim�ėLA,300)
tmr(pnlPB�����Ė���A or (not(PDL2_�p�h���Z���T�[����A) and not(FLOS3_LMT121)),tim�Ė���A,300)

if tim�ėLA then
	�Z�Ў��Ԍv���^���NA=ON
else if tim�Ė���A then
	�Z�Ў��Ԍv���^���NA=OFF
end if

if ldp(�Z�Ў��Ԍv���^���NA) then

	set�Z�Ў���A�E�N=get�N	
	set�Z�Ў���A�E��=get��	
	set�Z�Ў���A�E��=get��
	set�Z�Ў���A�E��=get��
	set�Z�Ў���A�E��=get��
	set�Z�Ў���A�E�b=get�b	

end if

if �Z�Ў��Ԍv���^���NA then

	�Z�Ў��ԃ^���NA�o��.D=sec(get�N)-sec(set�Z�Ў���A�E�N) '�ݒ肩��̌o�ߎ���
	rsec(�Z�Ў��ԃ^���NA�o��.D,�Z�Ў��ԃ^���NA�E�N)

else
	�Z�Ў��ԃ^���NA�E�N=0
	�Z�Ў��ԃ^���NA�E��=0
	�Z�Ў��ԃ^���NA�E��=0
	�Z�Ў��ԃ^���NA�E��=0
	�Z�Ў��ԃ^���NA�E��=0
	�Z�Ў��ԃ^���NA�E�b=0
end if


'------------------------------------------------------------------------------------------------------------
'�Z�Ў��Ԍv���^���NB

'set�Z�Ў���B�E�N

'�Z�Ў��ԃ^���NB�E�N
'�Z�Ў��ԃ^���NB�E��
'�Z�Ў��ԃ^���NB�E��
'�Z�Ў��ԃ^���NB�E��
'�Z�Ў��ԃ^���NB�E��
'�Z�Ў��ԃ^���NB�E�b
'�Z�Ў��ԃ^���NB�E�j��

tmr(pnlPB�����ėLB or PDL4_�p�h���Z���T�[����B or FLOS4_LMT121,tim�ėLB,300)
tmr(pnlPB�����Ė���B or (not(PDL4_�p�h���Z���T�[����B) and not(FLOS4_LMT121)),tim�Ė���B,300)

if tim�ėLB then
	�Z�Ў��Ԍv���^���NB=ON
else if tim�Ė���B then
	�Z�Ў��Ԍv���^���NB=OFF
end if

if ldp(�Z�Ў��Ԍv���^���NB) then

	set�Z�Ў���B�E�N=get�N	
	set�Z�Ў���B�E��=get��	
	set�Z�Ў���B�E��=get��
	set�Z�Ў���B�E��=get��
	set�Z�Ў���B�E��=get��
	set�Z�Ў���B�E�b=get�b	

end if

if �Z�Ў��Ԍv���^���NB then

	�Z�Ў��ԃ^���NB�o��.D=sec(get�N)-sec(set�Z�Ў���B�E�N) '�ݒ肩��̌o�ߎ���
	rsec(�Z�Ў��ԃ^���NB�o��.D,�Z�Ў��ԃ^���NB�E�N)
	
else
	�Z�Ў��ԃ^���NB�E�N=0
	�Z�Ў��ԃ^���NB�E��=0
	�Z�Ў��ԃ^���NB�E��=0
	�Z�Ў��ԃ^���NB�E��=0
	�Z�Ў��ԃ^���NB�E��=0
	�Z�Ў��ԃ^���NB�E�b=0
end if




'------------------------------------------------------------------------------------------------------------
'���ݎ����̐ݒ�
'------------------------------------------------------------------------------------------------------------
if LDP(Difu�����ݒ�) then
	�C�������E�N=get�N
	�C�������E��=get��
	�C�������E��=get��
	�C�������E��=get��
	�C�������E��=get��
	�C�������E�b=get�b
	�C�������E�j��=get�j��
	
	IND_�C�����j��=OFF
	IND_�C�����j��=OFF
	IND_�C���Ηj��=OFF
	IND_�C�����j��=OFF
	IND_�C���ؗj��=OFF
	IND_�C�����j��=OFF
	IND_�C���y�j��=OFF	
	select case  �C�������E�j��
		case 0
			IND_�C�����j��=ON
		case 1
			IND_�C�����j��=ON
		case 2
			IND_�C���Ηj��=ON
		case 3
			IND_�C�����j��=ON
		case 4
			IND_�C���ؗj��=ON
		case 5
			IND_�C�����j��=ON
		case 6
			IND_�C���y�j��=ON
	end select

end if

if LDP(IND_�C�����j��) then
	IND_�C�����j��=ON
	IND_�C�����j��=OFF
	IND_�C���Ηj��=OFF
	IND_�C�����j��=OFF
	IND_�C���ؗj��=OFF
	IND_�C�����j��=OFF
	IND_�C���y�j��=OFF
else if LDP(IND_�C�����j��) then
	IND_�C�����j��=OFF
	IND_�C�����j��=ON
	IND_�C���Ηj��=OFF
	IND_�C�����j��=OFF
	IND_�C���ؗj��=OFF
	IND_�C�����j��=OFF
	IND_�C���y�j��=OFF
else if LDP(IND_�C���Ηj��) then
	IND_�C�����j��=OFF
	IND_�C�����j��=OFF
	IND_�C���Ηj��=ON
	IND_�C�����j��=OFF
	IND_�C���ؗj��=OFF
	IND_�C�����j��=OFF
	IND_�C���y�j��=OFF
else if LDP(IND_�C�����j��) then
	IND_�C�����j��=OFF
	IND_�C�����j��=OFF
	IND_�C���Ηj��=OFF
	IND_�C�����j��=ON
	IND_�C���ؗj��=OFF
	IND_�C�����j��=OFF
	IND_�C���y�j��=OFF
else if LDP(IND_�C���ؗj��) then
	IND_�C�����j��=OFF
	IND_�C�����j��=OFF
	IND_�C���Ηj��=OFF
	IND_�C�����j��=OFF
	IND_�C���ؗj��=ON
	IND_�C�����j��=OFF
	IND_�C���y�j��=OFF
else if LDP(IND_�C�����j��) then
	IND_�C�����j��=OFF
	IND_�C�����j��=OFF
	IND_�C���Ηj��=OFF
	IND_�C�����j��=OFF
	IND_�C���ؗj��=OFF
	IND_�C�����j��=ON
	IND_�C���y�j��=OFF
else if LDP(IND_�C���y�j��) then
	IND_�C�����j��=OFF
	IND_�C�����j��=OFF
	IND_�C���Ηj��=OFF
	IND_�C�����j��=OFF
	IND_�C���ؗj��=OFF
	IND_�C�����j��=OFF
	IND_�C���y�j��=ON
end if


if ldp(�����ݒ�) then
	if 16 <= �C�������E�N and 99>�C�������E�N then
		if 1<=�C�������E��  and 12>=�C�������E�� then
		
			select case �C�������E��
			case 1 
				Days=31
			case 2 
				Days=29
			case 3 
				Days=31
			case 4 
				Days=30
			case 5 
				Days=31
			case 6 
				Days=30
			case 7 
				Days=31
			case 8 
				Days=31
			case 9 
				Days=30
			case 10	
				Days=31
			case 11	
				Days=30
			case 12	
				Days=31
			end select 

			if IND_�C�����j�� then
				�C�������E�j��=0
			else if IND_�C�����j�� then
				�C�������E�j��=1
			else if IND_�C���Ηj�� then
				�C�������E�j��=2
			else if IND_�C�����j�� then
				�C�������E�j��=3
			else if IND_�C���ؗj�� then
				�C�������E�j��=4
			else if IND_�C�����j�� then
				�C�������E�j��=5
			else if IND_�C���y�j�� then
				�C�������E�j��=6
			end if 

			if 1<=�C�������E�� and Days>=�C�������E�� then
				if 0<=�C�������E��  and 23>=�C�������E�� then
					if 0<=�C�������E�� and 59>=�C�������E�� then
						�C�������E�b=0
						wtime(�C�������E�N,�C�������E��,�C�������E��,�C�������E��,�C�������E��,�C�������E�b,�C�������E�j��)
					end if
				end if
				
			end if
		end if
	end if

	
end if
'------------------------------------------------------------------------------------------------------------

end if 'wait_tim

