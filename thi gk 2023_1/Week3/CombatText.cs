using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using DG.Tweening;

public class CombatText : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI combatText;

    private void Start()
    {
        combatText.transform.DOMoveY(transform.position.y + 10, 2f);
        combatText.DOFade(0, 2f);
        Destroy(gameObject, 2f);
    }
    public void OnInit(float txt)
    {
        combatText.SetText(txt.ToString());
    }
}
