from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import cm
from reportlab.lib import colors
from reportlab.platypus import (
    SimpleDocTemplate, Paragraph, Spacer, PageBreak,
    Table, TableStyle, HRFlowable, KeepTogether
)
from reportlab.lib.enums import TA_CENTER, TA_LEFT, TA_JUSTIFY

W, H = A4
doc = SimpleDocTemplate(
    "/mnt/user-data/outputs/Discrete_Math_Question_Bank.pdf",
    pagesize=A4,
    leftMargin=2*cm, rightMargin=2*cm,
    topMargin=2.2*cm, bottomMargin=2.2*cm
)

styles = getSampleStyleSheet()

# Custom styles
title_style = ParagraphStyle('Title2', parent=styles['Title'],
    fontSize=20, textColor=colors.HexColor('#1a237e'),
    spaceAfter=6, spaceBefore=4, alignment=TA_CENTER)

subtitle_style = ParagraphStyle('Subtitle', parent=styles['Normal'],
    fontSize=11, textColor=colors.HexColor('#37474f'),
    spaceAfter=12, alignment=TA_CENTER)

unit_style = ParagraphStyle('Unit', parent=styles['Heading1'],
    fontSize=14, textColor=colors.white,
    backColor=colors.HexColor('#1a237e'),
    spaceAfter=6, spaceBefore=10,
    borderPad=6, leftIndent=-10, rightIndent=-10)

section_style = ParagraphStyle('Section', parent=styles['Heading2'],
    fontSize=12, textColor=colors.HexColor('#1565c0'),
    spaceAfter=4, spaceBefore=8,
    borderPad=3)

q_style = ParagraphStyle('Question', parent=styles['Normal'],
    fontSize=10.5, textColor=colors.HexColor('#212121'),
    spaceAfter=3, spaceBefore=4,
    leftIndent=0)

ans_style = ParagraphStyle('Answer', parent=styles['Normal'],
    fontSize=10, textColor=colors.HexColor('#1b5e20'),
    spaceAfter=6, spaceBefore=2,
    leftIndent=14, borderPad=4,
    backColor=colors.HexColor('#f1f8e9'))

note_style = ParagraphStyle('Note', parent=styles['Normal'],
    fontSize=9.5, textColor=colors.HexColor('#4a148c'),
    spaceAfter=4, spaceBefore=2,
    leftIndent=14)

def unit_header(text):
    return [
        Spacer(1, 0.15*cm),
        Table([[Paragraph(text, ParagraphStyle('UH', parent=styles['Normal'],
            fontSize=13, textColor=colors.white, fontName='Helvetica-Bold'))]],
            colWidths=[W - 4*cm],
            style=TableStyle([
                ('BACKGROUND', (0,0), (-1,-1), colors.HexColor('#1a237e')),
                ('TEXTCOLOR', (0,0), (-1,-1), colors.white),
                ('PADDING', (0,0), (-1,-1), 8),
                ('ROWBACKGROUNDS', (0,0), (-1,-1), [colors.HexColor('#1a237e')]),
            ])),
        Spacer(1, 0.2*cm)
    ]

def section_header(text):
    return [
        Spacer(1, 0.1*cm),
        Table([[Paragraph(text, ParagraphStyle('SH', parent=styles['Normal'],
            fontSize=11, textColor=colors.HexColor('#1565c0'), fontName='Helvetica-Bold'))]],
            colWidths=[W - 4*cm],
            style=TableStyle([
                ('BACKGROUND', (0,0), (-1,-1), colors.HexColor('#e3f2fd')),
                ('LINEBELOW', (0,0), (-1,-1), 1.5, colors.HexColor('#1565c0')),
                ('PADDING', (0,0), (-1,-1), 5),
            ])),
        Spacer(1, 0.1*cm)
    ]

def Q(num, text):
    return Paragraph(f"<b>Q{num}.</b> {text}", q_style)

def A(text):
    return Paragraph(f"<b>Ans:</b> {text}", ans_style)

def note(text):
    return Paragraph(f"<i>Note: {text}</i>", note_style)

sp = lambda n=0.2: Spacer(1, n*cm)

# ─────────────────────────────────────────────────────────────────
story = []

# Cover
story += [
    sp(2),
    Paragraph("Discrete Mathematics", title_style),
    Paragraph("Comprehensive Question Bank with Solutions", subtitle_style),
    Paragraph("Based on Kenneth H. Rosen — Discrete Mathematics and Its Applications", subtitle_style),
    sp(0.3),
    HRFlowable(width="100%", thickness=2, color=colors.HexColor('#1a237e')),
    sp(0.3),
    Paragraph("End Semester Examination Preparation", ParagraphStyle('sub2', parent=styles['Normal'],
        fontSize=12, textColor=colors.HexColor('#c62828'), alignment=TA_CENTER)),
    sp(2),
    Paragraph("Topics Covered", ParagraphStyle('tc', parent=styles['Heading2'], alignment=TA_CENTER,
        textColor=colors.HexColor('#37474f'))),
    sp(0.2),
]

toc_data = [
    ["Unit", "Topic"],
    ["I", "Sets & Sequences · Logic · Proofs · Infinite Sets · Induction"],
    ["II", "Relations · Functions · Graphs · Posets & Lattices · Boolean Algebra"],
    ["III", "Counting · Combinatorics · Recurrences · Generating Functions"],
    ["IV", "Algebraic Structures: Groups, Rings, Fields, Vector Spaces"],
    ["V", "Graph Theory · Trees · Planarity · Network Flows"],
]
toc_table = Table(toc_data, colWidths=[2.5*cm, W - 7*cm])
toc_table.setStyle(TableStyle([
    ('BACKGROUND', (0,0), (-1,0), colors.HexColor('#1a237e')),
    ('TEXTCOLOR', (0,0), (-1,0), colors.white),
    ('FONTNAME', (0,0), (-1,0), 'Helvetica-Bold'),
    ('ROWBACKGROUNDS', (0,1), (-1,-1), [colors.HexColor('#e8eaf6'), colors.white]),
    ('GRID', (0,0), (-1,-1), 0.5, colors.HexColor('#9fa8da')),
    ('FONTSIZE', (0,0), (-1,-1), 10),
    ('PADDING', (0,0), (-1,-1), 6),
    ('ALIGN', (0,0), (0,-1), TA_CENTER),
]))
story.append(toc_table)
story.append(PageBreak())

# ═══════════════════════════════════════════════════════════
# UNIT I
# ═══════════════════════════════════════════════════════════
story += unit_header("UNIT I — Sets, Logic, Proofs, Infinite Sets & Mathematical Induction")

# 1. Finite Sets & Power Set
story += section_header("1. Finite Sets, Power Set, Cardinality, Cartesian Product")

qs = [
    ("1", "Define a finite set. Give three examples and state the cardinality of each.",
     "A finite set has a countable, limited number of elements. Examples: A = {1,2,3} → |A|=3; B = {a,b} → |B|=2; C = ∅ → |C|=0."),
    ("2", "What is the Power Set of S = {1, 2, 3}? How many elements does P(S) have?",
     "P(S) = {∅, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}}. Since |S|=3, |P(S)| = 2³ = 8."),
    ("3", "If |A| = m and |B| = n, what is |A × B|? Illustrate with A={a,b}, B={1,2,3}.",
     "|A × B| = m·n. Here |A×B| = 2×3 = 6. A×B = {(a,1),(a,2),(a,3),(b,1),(b,2),(b,3)}."),
    ("4", "Prove that for any set A, A ∪ ∅ = A and A ∩ ∅ = ∅.",
     "A ∪ ∅: x ∈ A∪∅ iff x∈A or x∈∅. Since x∈∅ is always false, x∈A∪∅ iff x∈A → A∪∅=A. A∩∅: x∈A∩∅ iff x∈A AND x∈∅. Since no x∈∅, A∩∅=∅."),
    ("5", "State and prove De Morgan's Laws for sets.",
     "Law 1: (A∪B)ᶜ = Aᶜ∩Bᶜ. Proof: x∈(A∪B)ᶜ ↔ x∉A∪B ↔ x∉A ∧ x∉B ↔ x∈Aᶜ ∧ x∈Bᶜ ↔ x∈Aᶜ∩Bᶜ. Law 2: (A∩B)ᶜ = Aᶜ∪Bᶜ. Proof is symmetric."),
    ("6", "Show that A ⊆ B if and only if A ∩ B = A.",
     "→: Assume A⊆B. Let x∈A∩B → x∈A and x∈B; trivially A∩B⊆A. For x∈A → x∈B (since A⊆B) → x∈A∩B. So A⊆A∩B. Hence A∩B=A. ←: Assume A∩B=A. Let x∈A → x∈A∩B → x∈B. So A⊆B."),
    ("7", "What is a vector/bit-string implementation of sets? Given U={1,2,3,4,5}, represent A={1,3,5} and B={2,3,5}. Find A∪B and A∩B using bit operations.",
     "A = 10101, B = 01101. A∪B = 10101 OR 01101 = 11101 = {1,2,3,5}. A∩B = 10101 AND 01101 = 00101 = {3,5}."),
    ("8", "Prove the distributive law: A∩(B∪C) = (A∩B)∪(A∩C).",
     "x ∈ A∩(B∪C) ↔ x∈A ∧ (x∈B ∨ x∈C) ↔ (x∈A ∧ x∈B) ∨ (x∈A ∧ x∈C) ↔ x∈(A∩B) ∨ x∈(A∩C) ↔ x∈(A∩B)∪(A∩C). ∎"),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

# 2. Propositional Logic
story += section_header("2. Propositional Logic, Truth Tables, Deduction, Resolution")
qs = [
    ("9", "Define proposition, conjunction, disjunction, negation, and implication with examples.",
     "Proposition: a statement with definite truth value. Conjunction p∧q (T only when both T). Disjunction p∨q (F only when both F). Negation ¬p (flips truth). Implication p→q (F only when p=T, q=F)."),
    ("10", "Construct a truth table for p → (q ∨ ¬r).",
     "8 rows (2³). Key result: the formula is F only when p=T, q=F, r=T. All other rows give T. The formula evaluates to F in exactly 1 of 8 cases."),
    ("11", "Show that (p → q) ≡ (¬p ∨ q) using a truth table.",
     "p=T,q=T: p→q=T, ¬p∨q=T. p=T,q=F: p→q=F, ¬p∨q=F. p=F,q=T: p→q=T, ¬p∨q=T. p=F,q=F: p→q=T, ¬p∨q=T. All rows match → equivalent."),
    ("12", "What is a tautology? Show p ∨ ¬p is a tautology.",
     "A tautology is a formula that is TRUE for all truth assignments. p∨¬p: if p=T → T∨F=T; if p=F → F∨T=T. True in all cases → tautology (Law of Excluded Middle)."),
    ("13", "Explain Modus Ponens and Modus Tollens with examples.",
     "Modus Ponens: From p→q and p, infer q. Example: 'If it rains, ground is wet; it rains; ∴ ground is wet.' Modus Tollens: From p→q and ¬q, infer ¬p. Example: 'If it rains, ground is wet; ground is not wet; ∴ it does not rain.'"),
    ("14", "What is Resolution? Use it to prove: from {p∨q, ¬p∨r, ¬q∨r}, derive r.",
     "Resolution rule: From (A∨C) and (¬C∨B), derive (A∨B). Step 1: Resolve p∨q with ¬p∨r → q∨r. Step 2: Resolve q∨r with ¬q∨r → r∨r = r. ∴ r is derived."),
    ("15", "Define Conjunctive Normal Form (CNF) and convert (p ∨ ¬q) ∧ (¬p ∨ r) to verify it is in CNF.",
     "CNF: conjunction of clauses, where each clause is a disjunction of literals. (p∨¬q)∧(¬p∨r) is already in CNF — two clauses each being a disjunction of literals."),
    ("16", "Prove that p ↔ q ≡ (p → q) ∧ (q → p) using a truth table.",
     "p=T,q=T: p↔q=T, (T→T)∧(T→T)=T∧T=T ✓. p=T,q=F: F vs (F)∧(T)=F ✓. p=F,q=T: F vs (T)∧(F)=F ✓. p=F,q=F: T vs (T)∧(T)=T ✓. Equivalent in all cases."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

# 3. Predicates & Quantifiers
story += section_header("3. Predicates, Quantifiers, Mathematical Proofs")
qs = [
    ("17", "Distinguish between universal and existential quantifiers. Give examples.",
     "∀x P(x) — Universal: 'For all x, P(x) holds.' Example: ∀x(x² ≥ 0) over reals. ∃x P(x) — Existential: 'There exists x such that P(x) holds.' Example: ∃x(x² = 4), since x=2 or x=−2."),
    ("18", "Negate the statement: ∀x∃y(x + y = 0). What does the negation mean?",
     "¬[∀x∃y(x+y=0)] = ∃x∀y(x+y≠0). Meaning: 'There exists some x for which no y satisfies x+y=0.' (This negation is false over integers since y=−x always works.)"),
    ("19", "Prove by contradiction: √2 is irrational.",
     "Assume √2 = p/q in lowest terms. Then 2 = p²/q² → p² = 2q² → p² is even → p is even → p=2k → 4k²=2q² → q²=2k² → q is even. Both p,q even contradicts lowest terms. ∴ √2 is irrational. ∎"),
    ("20", "Prove by contrapositive: If n² is odd, then n is odd.",
     "Contrapositive: If n is even, then n² is even. Proof: n=2k → n²=4k²=2(2k²) which is even. ∎ Since contrapositive is proved, the original statement holds."),
    ("21", "Prove directly: The sum of two even integers is even.",
     "Let a=2m and b=2n. Then a+b = 2m+2n = 2(m+n), which is divisible by 2. ∴ a+b is even. ∎"),
    ("22", "What is a proof by exhaustion? Illustrate with a small example.",
     "Checking all cases. Example: Prove n²+n is even for n∈{0,1,2,3}. n=0:0 (even), n=1:2 (even), n=2:6 (even), n=3:12 (even). All cases verified. (General proof uses induction.)"),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

# 4. Infinite Sets
story += section_header("4. Infinite Sets, Well-Ordering, Countable & Uncountable Sets, Cantor's Diagonalization")
qs = [
    ("23", "State the Well-Ordering Principle. Give an application.",
     "Well-Ordering Principle: Every non-empty subset of positive integers has a least element. Application: Used to prove the existence of quotient and remainder in integer division, and as a basis for proof by induction."),
    ("24", "Define countably infinite set. Show that the set of all integers ℤ is countable.",
     "A set is countably infinite if there is a bijection with ℕ. Bijection f: ℕ→ℤ: map 0→0, 1→1, 2→−1, 3→2, 4→−2, … i.e., f(2n)=n, f(2n−1)=−n. This is a bijection, so ℤ is countable."),
    ("25", "Prove that ℚ (rationals) is countable.",
     "List all fractions p/q (p∈ℤ, q∈ℕ) in a 2D grid and traverse diagonally (Cantor's zig-zag), skipping repeats. This gives a surjection ℕ→ℚ, proving ℚ is countable."),
    ("26", "State and prove Cantor's Diagonalization Theorem: (0,1) is uncountable.",
     "Assume a bijection f: ℕ→(0,1) exists. List: r₁=0.d₁₁d₁₂…, r₂=0.d₂₁d₂₂…, … Construct x=0.x₁x₂… where xᵢ=1 if dᵢᵢ≠1, else 0. Then x differs from every rᵢ in the i-th decimal digit → x is not in the list → contradiction. ∴ (0,1) is uncountable. ∎"),
    ("27", "Show that the power set P(ℕ) is uncountable.",
     "By Cantor's theorem, |P(A)| > |A| for any set A. Apply to A=ℕ: |P(ℕ)| > |ℕ| = ℵ₀. Since ℕ is the 'smallest' infinite set, P(ℕ) is uncountable. Alternatively, there is a bijection P(ℕ) ↔ {0,1}^ℕ ↔ real numbers in (0,1), which is uncountable."),
    ("28", "Define Schröder–Bernstein theorem and explain its significance.",
     "If there exist injections f: A→B and g: B→A, then there exists a bijection h: A→B (i.e., |A|=|B|). Significance: allows us to prove sets have equal cardinality without explicitly constructing a bijection — only injections in both directions are needed."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

# 5. Mathematical Induction
story += section_header("5. Mathematical Induction — Weak and Strong")
qs = [
    ("29", "State the Principle of Mathematical Induction (Weak) and prove: 1+2+…+n = n(n+1)/2.",
     "Base: n=1: LHS=1, RHS=1(2)/2=1 ✓. Inductive step: Assume 1+…+k = k(k+1)/2. Then 1+…+k+(k+1) = k(k+1)/2 + (k+1) = (k+1)(k/2+1) = (k+1)(k+2)/2. ∎"),
    ("30", "Prove by induction: 2ⁿ > n for all n ≥ 1.",
     "Base n=1: 2¹=2>1 ✓. Inductive step: Assume 2ᵏ>k. Then 2ᵏ⁺¹=2·2ᵏ>2k≥k+1 (since k≥1 → 2k≥k+1). ∴ 2ᵏ⁺¹>k+1. ∎"),
    ("31", "State Strong Induction. How does it differ from weak induction?",
     "Strong Induction: Assume P(1), P(2), …, P(k) all hold, then prove P(k+1). Weak assumes only P(k). Strong is useful when P(k+1) depends on multiple previous cases, e.g., Fibonacci recurrence or prime factorisation."),
    ("32", "Use strong induction to prove: every integer n ≥ 2 has a prime factorisation.",
     "Base n=2: 2 is prime → it is its own factorisation ✓. Inductive step: Assume all integers 2≤m<n have prime factorisations. If n is prime, done. If n is composite, n=ab with 2≤a,b<n. By strong IH, a and b each have prime factorisations, so their product gives n's prime factorisation. ∎"),
    ("33", "Prove by induction: ∑ᵢ₌₁ⁿ i² = n(n+1)(2n+1)/6.",
     "Base n=1: 1 = 1·2·3/6 = 1 ✓. Inductive: Assume true for k. For k+1: ∑ᵢ₌₁ᵏ⁺¹ i² = k(k+1)(2k+1)/6 + (k+1)² = (k+1)[k(2k+1)/6 + (k+1)] = (k+1)(2k²+7k+6)/6 = (k+1)(k+2)(2k+3)/6. ∎"),
    ("34", "What is the Fibonacci sequence? Use strong induction to prove F(n) < 2ⁿ for all n ≥ 1.",
     "F(1)=F(2)=1, F(n)=F(n-1)+F(n-2). Base: F(1)=1<2, F(2)=1<4 ✓. Inductive: Assume F(m)<2ᵐ for all m≤k. F(k+1)=F(k)+F(k-1)<2ᵏ+2ᵏ⁻¹<2ᵏ+2ᵏ=2ᵏ⁺¹. ∎"),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story.append(PageBreak())

# ═══════════════════════════════════════════════════════════
# UNIT II
# ═══════════════════════════════════════════════════════════
story += unit_header("UNIT II — Relations, Functions, Posets, Lattices & Boolean Algebra")

story += section_header("6. Relations and Their Properties")
qs = [
    ("35", "Define a binary relation on a set. List all properties a relation may have.",
     "A binary relation R on set A is a subset of A×A. Properties: (1) Reflexive: aRa ∀a. (2) Symmetric: aRb→bRa. (3) Antisymmetric: aRb ∧ bRa → a=b. (4) Transitive: aRb ∧ bRc → aRc. (5) Irreflexive: a∤Ra for any a."),
    ("36", "Give an example of a relation that is reflexive and symmetric but not transitive.",
     "On ℤ: aRb if |a−b| ≤ 1. Reflexive: |a−a|=0≤1 ✓. Symmetric: |a−b|=|b−a| ✓. Not transitive: 1R2 and 2R3 but |1−3|=2>1 → 1 ∤ R 3."),
    ("37", "What is an equivalence relation? Give an example and describe its equivalence classes.",
     "A relation that is reflexive, symmetric, and transitive. Example: Congruence mod 3 on ℤ: a≡b(mod 3). Equivalence classes: [0]={…,−3,0,3,6,…}, [1]={…,−2,1,4,7,…}, [2]={…,−1,2,5,8,…}."),
    ("38", "Define partial order. Is the 'divides' relation on ℕ a partial order?",
     "A partial order is reflexive, antisymmetric, and transitive. Divides (|): Reflexive: a|a ✓. Antisymmetric: a|b and b|a → a=b (for positives) ✓. Transitive: a|b and b|c → a|c ✓. Yes, divides is a partial order on ℕ."),
    ("39", "What are n-ary relations? Give an application.",
     "An n-ary relation on sets A₁,…,Aₙ is a subset of A₁×…×Aₙ. Application: Databases — each table row is a tuple in an n-ary relation. SQL SELECT/JOIN operations correspond to relational operations (projection, join, selection) on n-ary relations."),
    ("40", "Define the composition of relations. If R = {(1,2),(2,3)} and S = {(2,4),(3,1)}, find S∘R.",
     "S∘R = {(a,c) : ∃b, (a,b)∈R and (b,c)∈S}. (1,2)∈R and (2,4)∈S → (1,4). (2,3)∈R and (3,1)∈S → (2,1). So S∘R = {(1,4),(2,1)}."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("7. Functions and Bijections")
qs = [
    ("41", "Define injective (one-to-one), surjective (onto), and bijective functions.",
     "Injective: f(a)=f(b)→a=b (distinct inputs give distinct outputs). Surjective: ∀y∈B, ∃x∈A: f(x)=y (every output is hit). Bijective: both injective and surjective; implies |A|=|B|."),
    ("42", "Show f: ℝ→ℝ, f(x)=2x+3 is a bijection.",
     "Injective: f(a)=f(b) → 2a+3=2b+3 → a=b ✓. Surjective: Given y, solve x=(y-3)/2 ∈ℝ ✓. ∴ f is bijective."),
    ("43", "What is the inverse of a function? Find the inverse of f(x) = (x−1)/3.",
     "Inverse f⁻¹ satisfies f⁻¹(f(x))=x. Solve y=(x−1)/3 for x: x=3y+1. So f⁻¹(y)=3y+1. Verify: f(f⁻¹(y))=f(3y+1)=(3y+1−1)/3=y ✓."),
    ("44", "Prove that the composition of two bijections is a bijection.",
     "Let f:A→B and g:B→C be bijections. Injective: g∘f(a)=g∘f(b) → g(f(a))=g(f(b)) → f(a)=f(b) (g injective) → a=b (f injective). Surjective: For c∈C, ∃b∈B: g(b)=c (g surjective); ∃a∈A: f(a)=b (f surjective). So g∘f(a)=c. ∎"),
    ("45", "What is a floor function and ceiling function? Evaluate ⌊3.7⌋, ⌈3.2⌉, ⌊−2.3⌋.",
     "⌊x⌋ = greatest integer ≤ x. ⌈x⌉ = smallest integer ≥ x. ⌊3.7⌋=3. ⌈3.2⌉=4. ⌊−2.3⌋=−3."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("8. Posets, Lattices and Boolean Algebra")
qs = [
    ("46", "Define a poset. Draw the Hasse diagram for the divisibility poset on {1,2,3,4,6,12}.",
     "A poset (partially ordered set) is a set with a reflexive, antisymmetric, transitive relation. Hasse diagram for (D,|): 1 at bottom, 2 and 3 above 1, 4 and 6 above 2/3 respectively, 12 at top connected to 4 and 6."),
    ("47", "Define lattice. Is the divisibility poset on {1,2,3,6} a lattice?",
     "A lattice is a poset where every pair has a least upper bound (LUB/join, ∨) and greatest lower bound (GLB/meet, ∧). For {1,2,3,6} with |: 2∧3=1 (GCD), 2∨3=6 (LCM). All pairs have LUB and GLB → Yes, it is a lattice."),
    ("48", "State the principle of duality for lattices.",
     "The dual of a lattice statement is obtained by replacing ∨↔∧ and 0↔1 (swapping top and bottom). If a statement is true in all lattices, its dual is also true. Example: absorption law a∨(a∧b)=a dualises to a∧(a∨b)=a."),
    ("49", "Define a Boolean algebra. List its fundamental laws.",
     "Boolean algebra is a complemented distributive lattice (B, ∨, ∧, ¬, 0, 1). Laws: Commutative, Associative, Distributive (a∧(b∨c)=(a∧b)∨(a∧c)), Identity (a∨0=a, a∧1=a), Complement (a∨¬a=1, a∧¬a=0), Idempotent, Absorption, De Morgan's laws."),
    ("50", "Distinguish between distributive lattice and complemented lattice.",
     "Distributive: a∧(b∨c)=(a∧b)∨(a∧c) and dually. Complemented: every element a has a complement a' such that a∨a'=1 and a∧a'=0. A Boolean algebra is both. Not every lattice is distributive (e.g., pentagon N₅ lattice)."),
    ("51", "What is a Boolean function? Represent f(x,y,z) = x'y + xz as a sum of minterms.",
     "Boolean function maps {0,1}ⁿ → {0,1}. Minterms where f=1: x'y+xz=1. Evaluate all 8 inputs: f=1 at (0,1,0),(0,1,1),(1,0,1),(1,1,1). Sum of minterms: f = m₂+m₃+m₅+m₇ = Σm(2,3,5,7)."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story.append(PageBreak())

# ═══════════════════════════════════════════════════════════
# UNIT III
# ═══════════════════════════════════════════════════════════
story += unit_header("UNIT III — Counting, Combinatorics, Recurrences & Generating Functions")

story += section_header("9. Counting Principles")
qs = [
    ("52", "State the Sum Rule and Product Rule. Give one example of each.",
     "Sum Rule: If task A can be done in m ways and task B in n ways (mutually exclusive), total = m+n. Example: choosing a vowel (5) or digit (10) → 15. Product Rule: If task A has m ways and task B has n ways (independent), total = m×n. Example: 4 shirts × 3 pants = 12 outfits."),
    ("53", "State the Principle of Inclusion-Exclusion (PIE) for two and three sets.",
     "|A∪B| = |A|+|B|−|A∩B|. |A∪B∪C| = |A|+|B|+|C|−|A∩B|−|A∩C|−|B∩C|+|A∩B∩C|."),
    ("54", "In a class of 50, 30 study Math, 25 study CS, 10 study both. How many study at least one?",
     "|M∪C| = 30+25−10 = 45 students study at least one subject."),
    ("55", "State and prove the Pigeonhole Principle.",
     "If n+1 objects are placed into n boxes, at least one box contains 2+ objects. Proof by contradiction: If every box has ≤1 object, total objects ≤ n, contradicting n+1 objects. ∎ Example: Among 13 people, at least 2 share a birth month."),
    ("56", "A group of 5 integers is chosen from 1–8. Prove two must sum to 9.",
     "Pair the integers: {1,8},{2,7},{3,6},{4,5} — 4 pairs. Choosing 5 integers from 4 pairs → by Pigeonhole, at least 2 come from the same pair → they sum to 9. ∎"),
    ("57", "What is 'counting by bijection'? Give an example.",
     "Count set A by finding a bijection to set B whose size is known. Example: The number of subsets of {1,…,n} equals 2ⁿ, by bijecting each subset to its characteristic bit-vector in {0,1}ⁿ."),
    ("58", "Explain double counting with an example.",
     "Count a quantity in two different ways to derive an identity. Example: Count edges in complete graph Kₙ: each of n vertices has degree n-1 → sum of degrees = n(n-1). Each edge contributes 2 to degree sum → |E|=n(n-1)/2."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("10. Permutations, Combinations")
qs = [
    ("59", "What is P(n,r)? Calculate P(7,3).",
     "P(n,r) = n!/(n−r)! = number of ordered arrangements of r items from n. P(7,3) = 7×6×5 = 210."),
    ("60", "What is C(n,r)? Prove C(n,r)=C(n,n−r).",
     "C(n,r)=n!/(r!(n-r)!) = unordered selections. C(n,n−r)=n!/((n−r)!r!) = C(n,r). Equal by symmetry of the formula. Combinatorially: choosing r items to include is same as choosing n−r items to exclude."),
    ("61", "State and prove Pascal's Identity: C(n,k) = C(n−1,k−1) + C(n−1,k).",
     "Proof: Either element n is in the k-subset (C(n−1,k−1) ways for the rest) or it isn't (C(n−1,k) ways). These cases are disjoint and exhaustive → C(n,k)=C(n−1,k−1)+C(n−1,k). ∎"),
    ("62", "State the Binomial Theorem. Expand (x+y)⁴.",
     "Binomial Theorem: (x+y)ⁿ = Σₖ₌₀ⁿ C(n,k) xᵏ yⁿ⁻ᵏ. (x+y)⁴ = y⁴ + 4xy³ + 6x²y² + 4x³y + x⁴."),
    ("63", "How many ways can 8 people be arranged in a circle?",
     "Circular permutations of n people = (n−1)! = 7! = 5040."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("11. Recurrence Relations & Generating Functions")
qs = [
    ("64", "Define a linear recurrence relation. Solve aₙ = 5aₙ₋₁ − 6aₙ₋₂ with a₀=1, a₁=4.",
     "Characteristic equation: r²−5r+6=0 → (r−2)(r−3)=0 → r=2,3. General solution: aₙ=A·2ⁿ+B·3ⁿ. Using initial conditions: A+B=1, 2A+3B=4 → A=−1, B=2. So aₙ = −2ⁿ + 2·3ⁿ."),
    ("65", "Solve the Fibonacci recurrence Fₙ=Fₙ₋₁+Fₙ₋₂, F₁=F₂=1.",
     "Characteristic equation: r²−r−1=0 → r=(1±√5)/2. Roots φ=(1+√5)/2, ψ=(1−√5)/2. Fₙ=(φⁿ−ψⁿ)/√5 (Binet's formula). E.g., F₅ = (φ⁵−ψ⁵)/√5 = 5. ✓"),
    ("66", "What is a generating function? Find the generating function for the sequence 1,1,1,1,…",
     "Generating function of {aₙ} is G(x)=Σaₙxⁿ. For aₙ=1 ∀n: G(x)=1+x+x²+…=1/(1−x) for |x|<1."),
    ("67", "Use generating functions to solve: aₙ = aₙ₋₁ + 2, a₀=1.",
     "G(x)=Σaₙxⁿ. G(x)−a₀ = x·G(x) + 2x/(1−x). G(x)(1−x)=1+2x/(1−x). G(x)=(1−x+2x)/((1−x)²)=(1+x)/(1−x)². Partial fractions give aₙ=2n+1."),
    ("68", "Define exponential generating function (EGF). What is the EGF of aₙ=n!?",
     "EGF: G(x)=Σ(aₙ/n!)xⁿ. For aₙ=n!: EGF=Σ(n!/n!)xⁿ=Σxⁿ=1/(1−x). EGFs are particularly useful for counting ordered arrangements (permutations)."),
    ("69", "What is the partition of an integer? In how many ways can 5 be partitioned?",
     "A partition of n is a way to write n as sum of positive integers (order doesn't matter). Partitions of 5: 5; 4+1; 3+2; 3+1+1; 2+2+1; 2+1+1+1; 1+1+1+1+1 → p(5)=7."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story.append(PageBreak())

# ═══════════════════════════════════════════════════════════
# UNIT IV
# ═══════════════════════════════════════════════════════════
story += unit_header("UNIT IV — Algebraic Structures: Groups, Rings, Fields, Vector Spaces")

story += section_header("12. Groups, Semigroups, Monoids")
qs = [
    ("70", "Define binary operation, semigroup, monoid, and group.",
     "Binary op: ∗:A×A→A (closed). Semigroup: closed + associative. Monoid: semigroup + identity element e (e∗a=a∗e=a). Group: monoid + every element has an inverse (a∗a⁻¹=e)."),
    ("71", "Show (ℤ, +) is a group.",
     "Closure: a+b∈ℤ ✓. Associativity: (a+b)+c=a+(b+c) ✓. Identity: 0 (a+0=a) ✓. Inverse: −a (a+(−a)=0) ✓. ∴ (ℤ,+) is a group."),
    ("72", "What is an Abelian (commutative) group? Give two examples.",
     "An Abelian group additionally satisfies a∗b=b∗a. Examples: (ℝ,+) since a+b=b+a. (ℤₙ,+ₙ) since addition mod n is commutative."),
    ("73", "State Lagrange's Theorem for groups.",
     "If G is a finite group and H is a subgroup of G, then |H| divides |G|. Equivalently, the order of any element divides the group order. Example: In (ℤ₆,+), subgroups have orders 1, 2, 3, 6 — all divisors of 6."),
    ("74", "Define group homomorphism and isomorphism.",
     "Homomorphism φ: G→H satisfies φ(a∗b)=φ(a)•φ(b). Isomorphism: a bijective homomorphism. Example: φ: (ℝ,+)→(ℝ₊,×) defined by φ(x)=eˣ is an isomorphism since e^(x+y)=eˣ·eʸ."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("13. Rings and Fields")
qs = [
    ("75", "Define a ring. Is (ℤ, +, ×) a ring?",
     "A ring (R,+,·) satisfies: (R,+) is abelian group; · is associative; distributive laws hold. (ℤ,+,×): Addition is abelian group ✓; multiplication is associative ✓; distributive ✓. Yes, ℤ is a ring (also commutative with unity)."),
    ("76", "What is the difference between a ring and a field?",
     "A field is a commutative ring with unity where every non-zero element has a multiplicative inverse. ℤ is a ring but not a field (2 has no integer inverse). ℚ, ℝ, ℂ are fields. Finite fields ℤₚ (p prime) are also fields."),
    ("77", "Show that ℤ₅ under addition and multiplication mod 5 is a field.",
     "ℤ₅={0,1,2,3,4}. Addition forms abelian group ✓. Multiplication is commutative and associative ✓. Distributive ✓. Multiplicative inverses: 1⁻¹=1, 2⁻¹=3 (2×3=6≡1), 3⁻¹=2, 4⁻¹=4 (4×4=16≡1) ✓. ∴ ℤ₅ is a field."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("14. Vector Spaces and Basis")
qs = [
    ("78", "Define a vector space over a field F. List the axioms.",
     "A vector space V over field F satisfies: (V,+) is abelian group; scalar multiplication: c·v∈V; c(u+v)=cu+cv; (c+d)v=cv+dv; (cd)v=c(dv); 1·v=v. Examples: ℝⁿ over ℝ, polynomials over ℝ."),
    ("79", "What is linear independence? Are {(1,0),(0,1),(1,1)} linearly independent in ℝ²?",
     "Vectors v₁,…,vₖ are linearly independent if c₁v₁+…+cₖvₖ=0 implies all cᵢ=0. For {(1,0),(0,1),(1,1)}: c₁(1,0)+c₂(0,1)+c₃(1,1)=(0,0) → c₁+c₃=0 and c₂+c₃=0. Set c₃=1: c₁=c₂=−1≠0. Not independent."),
    ("80", "Define basis and dimension of a vector space.",
     "A basis is a linearly independent set that spans V. Dimension = number of vectors in any basis. Example: {(1,0),(0,1)} is the standard basis for ℝ². dim(ℝ²)=2. Every vector in ℝ² is uniquely expressible as a linear combination of basis vectors."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story.append(PageBreak())

# ═══════════════════════════════════════════════════════════
# UNIT V
# ═══════════════════════════════════════════════════════════
story += unit_header("UNIT V — Graph Theory, Trees, Planarity & Network Flows")

story += section_header("15. Graph Basics, Isomorphism, Subgraphs")
qs = [
    ("81", "Define graph, simple graph, multigraph, and pseudograph.",
     "Graph G=(V,E): vertices V, edges E ⊆ V×V. Simple graph: no self-loops, no multiple edges. Multigraph: allows multiple edges between same vertices. Pseudograph: allows self-loops too."),
    ("82", "What is the Handshaking Lemma? Prove it.",
     "Σ deg(v) = 2|E|. Proof: Each edge {u,v} contributes 1 to deg(u) and 1 to deg(v), total contribution 2 per edge → Σdeg(v)=2|E|. Corollary: Number of odd-degree vertices is always even."),
    ("83", "Define graph isomorphism. Show K₃ and the cycle C₃ are isomorphic.",
     "Graphs G and H are isomorphic if there is a bijection f:V(G)→V(H) preserving adjacency. K₃ has vertices {a,b,c} all adjacent; C₃ has vertices {1,2,3} in a cycle. Map a↔1, b↔2, c↔3. Both have same edges under this mapping. ∴ K₃≅C₃."),
    ("84", "Define walk, path, circuit, and cycle.",
     "Walk: sequence v₀,e₁,v₁,…,eₖ,vₖ of alternating vertices and edges. Path: walk with no repeated vertices. Circuit: closed walk (v₀=vₖ) no repeated edges. Cycle: closed path, no repeated vertices (except endpoints)."),
    ("85", "What invariants are preserved under graph isomorphism?",
     "Number of vertices, number of edges, degree sequence, number of connected components, girth (length of shortest cycle), chromatic number, planarity. If any invariant differs between two graphs, they are NOT isomorphic."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("16. Connectivity, Euler & Hamiltonian Graphs")
qs = [
    ("86", "Define connected graph. State Euler's theorem for Eulerian circuits.",
     "Connected: there is a path between every pair of vertices. Euler's theorem: A connected graph has an Eulerian circuit (uses every edge exactly once, returns to start) iff every vertex has even degree."),
    ("87", "Does the Königsberg bridge graph have an Euler path? Explain.",
     "The Königsberg graph has 4 vertices with degrees 3, 3, 5, 3 — all odd. An Euler path requires exactly 0 or 2 vertices of odd degree. Since all 4 are odd, no Euler path exists. This was Euler's original 1736 result."),
    ("88", "Define Hamiltonian path and circuit. State Dirac's theorem.",
     "Hamiltonian path visits every vertex exactly once; Hamiltonian circuit is a closed Hamiltonian path. Dirac's theorem: If G is simple with n≥3 vertices and every vertex has degree ≥ n/2, then G has a Hamiltonian circuit."),
    ("89", "What is graph connectivity? Define vertex connectivity and edge connectivity.",
     "Connectivity κ(G) = min vertices to remove to disconnect G. Edge connectivity λ(G) = min edges to remove. Whitney's theorem: κ(G) ≤ λ(G) ≤ min{deg(v)}. Example: for Kₙ, κ=λ=n−1."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("17. Trees")
qs = [
    ("90", "Define a tree. State five equivalent characterisations.",
     "A tree is a connected acyclic graph. Equivalents: (1) Connected, no cycles. (2) Connected, |E|=|V|−1. (3) Acyclic, |E|=|V|−1. (4) Any two vertices connected by exactly one path. (5) Connected but removing any edge disconnects it."),
    ("91", "What are rooted trees and binary trees?",
     "Rooted tree: one vertex designated as root; edges directed away from root. Binary tree: rooted tree where each node has at most 2 children (left and right). Full binary tree: every internal node has exactly 2 children. Complete binary tree: all levels full except possibly the last."),
    ("92", "Define center of a tree. How do you find it?",
     "Center: the set of vertices that minimise the eccentricity (max distance to any vertex). Algorithm: Repeatedly remove all leaf vertices (leaves of current tree) until 1 or 2 vertices remain. These are the center(s). A tree has 1 or 2 centers."),
    ("93", "What is a spanning tree? Describe Kruskal's and Prim's algorithms.",
     "A spanning tree of graph G is a subgraph that is a tree containing all vertices. Kruskal's: Sort edges by weight, add cheapest edge that doesn't form a cycle. Prim's: Start from any vertex, repeatedly add the cheapest edge connecting tree to a non-tree vertex. Both give Minimum Spanning Trees (MST)."),
    ("94", "Define fundamental circuits and cut sets with respect to a spanning tree T of G.",
     "For spanning tree T: Adding any non-tree edge e to T creates exactly one cycle → fundamental circuit of e. Removing any tree edge e from T splits T → the edges crossing this partition form a fundamental cut set. Total: |E|−|V|+1 fundamental circuits, |V|−1 fundamental cut sets."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("18. Planar Graphs")
qs = [
    ("95", "Define planar graph. State Euler's formula for planar graphs.",
     "A planar graph can be drawn in the plane with no crossing edges. Euler's formula: v − e + f = 2, where v=vertices, e=edges, f=faces (including outer face). Example: K₄: v=4, e=6, f=4 → 4−6+4=2 ✓."),
    ("96", "Prove: For a simple connected planar graph with v≥3, e ≤ 3v−6.",
     "Each face is bounded by ≥3 edges, each edge borders ≤2 faces → 3f ≤ 2e → f ≤ 2e/3. Euler: v−e+f=2 → f=2−v+e. So 2−v+e ≤ 2e/3 → 6−3v+3e ≤ 2e → e ≤ 3v−6. ∎"),
    ("97", "Show K₅ is non-planar.",
     "K₅: v=5, e=10. Check: 3v−6=9. But e=10 > 9 → violates the inequality for planar graphs → K₅ is non-planar. ∎"),
    ("98", "Show K₃,₃ is non-planar using Euler's formula.",
     "K₃,₃: v=6, e=9. Bipartite → no odd cycles → every face has ≥4 edges → 4f≤2e → f≤e/2. Euler: 2=v−e+f ≤ 6−9+9/2=1.5. Contradiction → K₃,₃ is non-planar. ∎"),
    ("99", "State Kuratowski's theorem.",
     "A graph is planar if and only if it contains no subgraph homeomorphic (subdivision) to K₅ or K₃,₃. This is the complete characterisation of planarity in terms of forbidden minors."),
    ("100", "Define 1-isomorphism and 2-isomorphism of graphs.",
     "1-isomorphism: graphs are isomorphic (same abstract graph structure). 2-isomorphism (Whitney): Two graphs are 2-isomorphic if one can be obtained from the other by a sequence of 'twisting' at 2-separations. 2-isomorphic graphs have the same cycle matroid."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("19. Network Flows")
qs = [
    ("101", "Define a flow network, flow, and max-flow.",
     "Flow network: directed graph with capacity c(u,v)≥0 on each edge, source s and sink t. A flow f satisfies: 0≤f(u,v)≤c(u,v) (capacity) and for all v≠s,t: Σf(u,v)=Σf(v,w) (conservation). Max-flow: maximum value |f|=Σf(s,v)."),
    ("102", "State the Max-Flow Min-Cut Theorem.",
     "The maximum value of a flow from s to t equals the minimum capacity of an s-t cut. An s-t cut partitions V into S∋s and T∋t; its capacity = Σc(u,v) for edges u∈S, v∈T. This fundamental theorem (Ford-Fulkerson) connects flow and connectivity."),
    ("103", "Describe the Ford-Fulkerson algorithm for max-flow.",
     "1. Start with zero flow. 2. Find an augmenting path from s to t in the residual graph (using BFS/DFS). 3. Send flow equal to the bottleneck capacity along this path. 4. Update residual capacities. 5. Repeat until no augmenting path exists. Final flow = max-flow."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

story += section_header("20. Graph Colouring & Combinatorial Graphs")
qs = [
    ("104", "Define chromatic number χ(G). What is χ(Kₙ)?",
     "χ(G) = minimum number of colors needed to color vertices so no adjacent vertices share a color. χ(Kₙ)=n since every pair of vertices is adjacent. χ(cycle C_{2k})=2 (bipartite), χ(C_{2k+1})=3 (odd cycle)."),
    ("105", "State the Four Color Theorem.",
     "Every planar graph is 4-colorable (χ(G)≤4 for planar G). Proved by Appel and Haken in 1976 using computer-assisted case analysis — the first major theorem proved with computers."),
    ("106", "Define a bipartite graph. Give a characterisation in terms of cycles.",
     "A bipartite graph G=(A∪B, E) has vertices partitioned into two sets with all edges going between parts. Characterisation: G is bipartite iff it contains no odd-length cycles. Example: Trees are bipartite; K₃ is not (it's an odd cycle)."),
]
for q in qs:
    story += [Q(q[0], q[1]), A(q[2]), sp(0.15)]

# Final note
story += [
    sp(0.4),
    HRFlowable(width="100%", thickness=1.5, color=colors.HexColor('#1a237e')),
    sp(0.2),
    Paragraph(
        "<b>Study Tips:</b> Focus on proofs (induction, contradiction, direct), truth tables, "
        "recurrence relation solutions (characteristic roots), Euler's formula, spanning tree algorithms, "
        "and the Max-Flow Min-Cut theorem. Know all definitions precisely.",
        ParagraphStyle('tip', parent=styles['Normal'], fontSize=10,
            textColor=colors.HexColor('#4a148c'), backColor=colors.HexColor('#f3e5f5'),
            borderPad=8, spaceAfter=6)
    ),
    Paragraph(
        "Reference: Kenneth H. Rosen — Discrete Mathematics and Its Applications, 7th/8th Edition",
        ParagraphStyle('ref', parent=styles['Normal'], fontSize=9,
            textColor=colors.HexColor('#546e7a'), alignment=TA_CENTER, spaceBefore=8)
    ),
]

doc.build(story)
print("PDF created successfully.")