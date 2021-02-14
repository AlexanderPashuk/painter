object App: TApp
  Left = 0
  Top = 0
  Caption = 'Painter'
  ClientHeight = 335
  ClientWidth = 538
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object AppCanvas: TImage
    Left = 10
    Top = 8
    Width = 401
    Height = 319
    OnMouseDown = AppCanvasMouseDown
    OnMouseMove = AppCanvasMouseMove
    OnMouseUp = AppCanvasMouseUp
  end
  object Figure: TRadioGroup
    Left = 417
    Top = 8
    Width = 112
    Height = 145
    Caption = 'Figure'
    ItemIndex = 0
    Items.Strings = (
      'Pen'
      'Line'
      'Circle'
      'Rect')
    TabOrder = 0
    OnClick = FigureClick
  end
  object Line: TRadioGroup
    Left = 417
    Top = 167
    Width = 112
    Height = 146
    Caption = 'Line'
    ItemIndex = 0
    Items.Strings = (
      'solid'
      'dashed'
      'dotted'
      'dash-dotted')
    TabOrder = 1
    OnClick = LineClick
  end
end
