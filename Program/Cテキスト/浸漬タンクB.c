'�Z�Ѓ^���NB
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�Z�Ѓ^���NB�Ǘ� �����Ǘ�
'	
'===================================================================================================================
'�y ���������� �z
if CR2008 then
    �Z�Ѓ^���NBAutoMode=ON
    �Z�Ѓ^���NBAutoRun=OFF
    �Z�Ѓ^���NB����=ON
    �Z�Ѓ^���NBOrgErr=OFF
    �Z�Ѓ^���NBErr=OFF
    �Z�Ѓ^���NBEmg=OFF
    �Z�Ѓ^���NBstep=0
    �Z�Ѓ^���NBErrStep=0
    �Z�Ѓ^���NBOrgErrStep=0
    �Z�Ѓ^���NBEmgStep=0

end if
'===================================================================================================================
'�y ���_ �z
�Z�Ѓ^���NBOrg=1


'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�Z�Ѓ^���NBEmg=ON
	�Z�Ѓ^���NBEmgStep=1
end if

select case �Z�Ѓ^���NBEmgStep

case 0

case 1
	ejectSV11_�����d����B=OFF
	inc(�Z�Ѓ^���NBEmgStep)
	
case 2
	if ResetFlg then
		inc(�Z�Ѓ^���NBEmgStep)
	end if
	
case 3
	if StartFlg then
		res(TIM_��pON_B)
		res(TIM_��pOFF_B)	
		�Z�Ѓ^���NBEmgStep=0
	end if

end select 


'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

	tmr(PDL3_�p�h���Z���T�[���B,tim_PDL3_�p�h���Z���T�[���B,20)
	tmr(PDL4_�p�h���Z���T�[����B,tim_PDL4_�p�h���Z���T�[����B,20)

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �Z�Ѓ^���NBAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �Z�Ѓ^���NBAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �Z�Ѓ^���NBEmg	���̏��~

if SSW3_�������[�h  and not(�A���t�@���ă��[�h) then

	RLY5_�p�h���Z���T�d��=ON	

	if �O������������ and �O�����H��step=0 then

		tmr(TIM_��pON_B, #1200) 'ON=10�b
		tmr(TIM_��pOFF_B, #9000) 'OFF=30��
		if ldp(TIM_��pOFF_B.B) then
			res(TIM_��pOFF_B) '�����̃^�C�}�[���N���A���A30�����Ƃ̃g���K�𔭐�
			res(TIM_��pON_B)
		end if
		

		if not(SV62_�r���o���u�JB) and not(pnlPB�����Ė���B) and (pnlPB�����ėLB or PDL4_�p�h���Z���T�[����B or FLOS4_LMT121 or (DM_B�^���N�ݒ�l>0 and �C���^�[�o��������)) then
			if not(TIM_��pON_B.B) then
				extSV11_�����d����B=ON
			else
				extSV11_�����d����B=OFF	
			end if

		else
			extSV11_�����d����B=OFF	
		end if

	else
		extSV11_�����d����B=OFF		
		res(TIM_��pOFF_B)	'�����̃^�C�}�[���N���A���A30�����Ƃ̃g���K�𔭐�		
		res(TIM_��pON_B)
	end if

else
	extSV11_�����d����B=OFF		
	RLY5_�p�h���Z���T�d��=OFF
end if
