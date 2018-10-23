VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Form2"
   ClientHeight    =   3015
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4560
   LinkTopic       =   "Form2"
   ScaleHeight     =   3015
   ScaleWidth      =   4560
   StartUpPosition =   3  '窗口缺省
   Begin VB.TextBox Text3 
      Height          =   495
      Index           =   1
      Left            =   2280
      TabIndex        =   10
      Text            =   "Text3"
      Top             =   2160
      Width           =   855
   End
   Begin VB.CommandButton Command2 
      Caption         =   "求解"
      Height          =   375
      Left            =   3480
      TabIndex        =   9
      Top             =   720
      Width           =   855
   End
   Begin VB.CommandButton Command1 
      Caption         =   "CLEAR"
      Height          =   495
      Left            =   3480
      TabIndex        =   8
      Top             =   1560
      Width           =   855
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Index           =   0
      Left            =   2280
      TabIndex        =   7
      Text            =   "Text3"
      Top             =   1560
      Width           =   855
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   240
      TabIndex        =   6
      Text            =   "Text2"
      Top             =   1560
      Width           =   1455
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Index           =   2
      Left            =   2280
      TabIndex        =   2
      Text            =   "Text1"
      Top             =   720
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Index           =   1
      Left            =   1286
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   720
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Index           =   0
      Left            =   240
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   720
      Width           =   855
   End
   Begin VB.Label Label2 
      Caption         =   "解"
      Height          =   375
      Left            =   2280
      TabIndex        =   11
      Top             =   1200
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "常数项"
      Height          =   255
      Index           =   2
      Left            =   2280
      TabIndex        =   5
      Top             =   360
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   "一次项"
      Height          =   255
      Index           =   1
      Left            =   1320
      TabIndex        =   4
      Top             =   360
      Width           =   855
   End
   Begin VB.Label Label1 
      Caption         =   " 二次项"
      Height          =   255
      Index           =   0
      Left            =   240
      TabIndex        =   3
      Top             =   360
      Width           =   855
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command2_Click()

Dim a As Double, b As Double, c As Double

a = Val(Text1(0).Text): b = Val(Text1(1).Text): c = Val(Text1(2).Text)

If delta(a, b, c) < 0 Then

Text2.Text = "原方程无解"

Else

Text3(0).Text = Str((-b + sqrt(delta(a, b, c))) / (2 * a))
Text3(1).Text = Str((-b - sqrt(delta(a, b, c))) / (2 * a))

End Sub

Private Sub Form_Load()

Call clear

End Sub

Public Function delta(ByVal a As Double, ByVal b As Double, ByVal c As Double) As Double

delta = b * b - 4 * a * c

End Function

Public Sub clear()

Text1(0).Text = ""
Text1(1).Text = ""
Text1(2).Text = ""

Text2.Text = ""

Text3(0).Text = ""
Text3(1).Text = ""

End Sub

