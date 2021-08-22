using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;


public class SceneShortcut : EditorWindow
{
    private readonly Vector2 _buttonMinSize = new Vector2(200,40);
    private readonly Vector2 _buttonMaxSize = new Vector2(300,60);
    private Vector2 _scrollRange = Vector2.zero;

    //!scene取得用
    static List<string> _pathList = new List<string>();

    //!フォルダ名・拡張子削除用
    static List<string> _pathListFixFile = new List<string>();
    static List<string> _pathListFixExtension = new List<string>();

    [MenuItem("Scene/SceneShortcut")]
    static void ShowWindow()
    {
        EditorWindow.GetWindow<SceneShortcut>();
    }

    private void OnGUI()
    {
        GUIStyle _buttonStyle = new GUIStyle("button") { fontSize = 15 };
        GUILayoutOption[] _layoutOptions = new GUILayoutOption[]
        {
            GUILayout.MinWidth(_buttonMinSize.x),
            GUILayout.MinHeight(_buttonMinSize.y),
            GUILayout.MaxWidth(_buttonMaxSize.x),
            GUILayout.MaxHeight(_buttonMaxSize.y)
        };

        _pathList.Clear();
        _pathListFixFile.Clear();
        _pathListFixExtension.Clear();
        foreach (var _id in AssetDatabase.FindAssets("t:Scene", new[] { "Assets/Scenes" }))
        {
            var _assetPath = AssetDatabase.GUIDToAssetPath(_id);
            _pathList.Add(_assetPath);
        }

        _scrollRange = EditorGUILayout.BeginScrollView(_scrollRange);

        for (int i = 0; i < _pathList.Count; i++)
        {
            _pathListFixFile.Add(_pathList[i].Replace("Assets/Scenes/", ""));
            _pathListFixExtension.Add(_pathListFixFile[i].Replace(".unity", ""));

            if (GUILayout.Button(_pathListFixExtension[i], _buttonStyle, _layoutOptions))
            {
                if (!EditorSceneManager.SaveModifiedScenesIfUserWantsTo(new UnityEngine.SceneManagement.Scene[] { SceneManager.GetActiveScene() })) return;
                EditorSceneManager.OpenScene(_pathList[i]);
            }
        }

        EditorGUILayout.EndScrollView();
    }
}
