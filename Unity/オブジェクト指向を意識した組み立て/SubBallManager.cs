using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UniRx;
using UniRx.Triggers;

namespace Es.InkPainter.Sample
{
    [RequireComponent(typeof(Collider), typeof(MeshRenderer))]
    public class SubBallManager : MonoBehaviour
    {
        #region Class
        private SubBallPainter _subBallPainter = null;
        private SetMaterial _setMaterial = null;
        #endregion

        #region SubBallPainter
        [SerializeField]
        private Brush _brush = null;
        [SerializeField]
        private ParticleSystem[] _effects;
        [SerializeField]
        private Rigidbody _myRigidbody = null;
        #endregion

        #region SetMaterial
        [SerializeField]
        private int _materialsNum = 1;
        #endregion

        private Color _paintColor = Color.white;
        private int _effectNumber = 0;

        public Color SubPaintColor
        {
            set => _paintColor = value;
            get => _paintColor;
        }

        private void Awake()
        {
            AddClass();

            //!勢いあるときの水しぶきの色を、ボディーの色と同じにする
            _effectNumber = _materialsNum;

            _setMaterial.SetMaterialAwake(this, _materialsNum);
        }

        private void Start()
        {
            _myRigidbody = this.GetComponent<Rigidbody>();
            Debug.Assert(_myRigidbody != null, "_rigidbodyがnullです");

            _subBallPainter.SubBallPainterStart(_brush, _effects, _myRigidbody, _paintColor, _effectNumber);

            //! UniRxを利用した呼び出し
            this.OnCollisionStayAsObservable()
                .Subscribe(collision =>
                {
                    _subBallPainter.OnPaintCanvasHit(collision);
                });
        }

        private void AddClass()
        {
            _setMaterial = gameObject.AddComponent<SetMaterial>();
            _subBallPainter = gameObject.AddComponent<SubBallPainter>();
        }
    }
}