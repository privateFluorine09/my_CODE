VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3015
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3015
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton Command2 
      Caption         =   "CLEAR"
      Height          =   495
      Left            =   2400
      TabIndex        =   5
      Top             =   1800
      Width           =   1335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "计算"
      Height          =   495
      Left            =   720
      TabIndex        =   4
      Top             =   1800
      Width           =   1335
   End
   Begin VB.TextBox Text1 
      Height          =   615
      Index           =   1
      Left            =   2400
      MultiLine       =   -1  'True
      TabIndex        =   1
      Text            =   "Form3.frx":0000
      Top             =   720
      Width           =   1335
   End
   Begin VB.TextBox Text1 
      Height          =   615
      Index           =   0
      Left            =   720
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   720
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "五级制"
      Height          =   495
      Index           =   1
      Left            =   2400
      TabIndex        =   3
      Top             =   240
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   " 百分制"
      Height          =   495
      Index           =   0
      Left            =   720
      TabIndex        =   2
      Top             =   240
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()

Text1(1).Text = result(Val(Text1(0).Text))

End Sub

Private Sub Command2_Click()

Call clear

End Sub

Private Sub Form_Load()
 
Call clear
 
End Sub

Public Sub clear()

Text1(0) = ""
Text1(1) = ""

End Sub

Public Function result(score As Double) As String

Select Case score

Case Is > 100
result = "分数输入有误，请重新输入"

Case Is < 0
result = "分数输入有误，请重新输入"

Case Is >= 90
result = "优秀"

Case Is >= 80
result = "良好"

Case Is >= 70
result = "中等"

Case Is >= 60
result = "及格"

Case Else
result = "不及格"

End Select

End Function

